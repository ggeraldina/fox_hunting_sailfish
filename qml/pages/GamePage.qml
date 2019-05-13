import QtQuick 2.0
import Sailfish.Silica 1.0
import QtMultimedia 5.6
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB
import TablesCompUser 1.0
import "components/cells_field"

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property string typeGame: "AI"
    property int spacingGrid: 1    
    property int baseFieldSize: settings.settingBaseTableSize
    property int quantityFoxes: settings.settingNumberFoxes
    property int speedStepComputer: settings.settingSpeedStepComp
    property int level: settings.settingLevel
    property string username: settings.settingUserName
    property string nameComp: qsTr("Device")
    property int baseWidthHeight: page.width * (9 / baseFieldSize) / 15
    property string tableName: "gameStatistics"

    Connections {
        target: settings
    }

    SoundEffect {
        id: soundEffect
        source: "qrc:/soundeffects/shot.wav"
        volume : settings.settingVolumeEffects
        loops : 1
    }


    TablesCompUser {
        id: dataModel
        onAddFoxUser: {
            if (settings.settingSavingGames == "true") {
                var field = "User"
                var fox = 1
                var shot = 0
                DB.dbInsertRowLocationGameSave(level, quantityFoxes, baseFieldSize, field, index, fox, shot)
            }
        }
        onShotUser: {
            soundEffect.play()
            if (settings.settingSavingGames == "true") {
                var field = "User"
                var fox = 0
                var shot = 1
                DB.dbInsertRowLocationGameSave(level, quantityFoxes, baseFieldSize, field, index, fox, shot)
            }
        }
        onShotComp: {
            soundEffect.play()
            if (settings.settingSavingGames == "true") {
                var field = "Comp"
                var fox = 0
                var shot = 1
                DB.dbInsertRowLocationGameSave(level, quantityFoxes, baseFieldSize, field, index, fox, shot)
            }
        }
        onWinUser: {
            if (settings.settingSavingStatistics == "true") {
                var obj = { date: new Date(),
                    sizeField: baseFieldSize,
                    countFoxes: quantityFoxes,
                    winner: username,
                    level: level,
                    stepsComp: countStepsComp,
                    stepsUser: countStepsUser,
                }
                DB.dbInsertRowGameStatistics(tableName, JSON.stringify(obj))
            }            
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User")
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "Comp")
            var statusGame = "new"
            DB.dbInsertRowGameStatus(typeGame, level, quantityFoxes, baseFieldSize, statusGame)
            pageStack.replace(Qt.resolvedUrl("WinGamePage.qml"))
        }
        onWinComp: {
            if (settings.settingSavingStatistics == "true") {
                var obj = { date: new Date(),
                    sizeField: baseFieldSize,
                    countFoxes: quantityFoxes,
                    winner: nameComp,
                    level: level,
                    stepsComp: countStepsComp,
                    stepsUser: countStepsUser,
                }
                DB.dbInsertRowGameStatistics(tableName, JSON.stringify(obj))
            }
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User")
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "Comp")
            var statusGame = "new"
            DB.dbInsertRowGameStatus(typeGame, level, quantityFoxes, baseFieldSize, statusGame)
            pageStack.replace(Qt.resolvedUrl("LoseGamePage.qml"))
        }
    }

    Column {
        id: column
        anchors {
            top: page.top
            topMargin: 20
            right: page.right
            left: page.left
            bottom: page.bottom
        }
        spacing: Theme.paddingMedium

        Column {
            rotation: settings.settingRotationFieldTop
            transformOrigin: Item.Center
            spacing: Theme.paddingMedium
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                text: nameComp + qsTr(" (steps ") + dataModel.countStepsComp + qsTr(")")
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeSmall
            }

            Grid {
                spacing: spacingGrid
                height: spacingGrid * baseFieldSize + baseWidthHeight * (baseFieldSize + 1)
                columns: 2

                Rectangle {
                      width: baseWidthHeight
                      height: baseWidthHeight
                      color: "darkblue";
                }

                FieldTableLitters {

                }

                FieldTableDigits{

                }

                Item {
                      width: baseWidthHeight * baseFieldSize
                      height: baseWidthHeight * baseFieldSize

                      Grid {
                          spacing: spacingGrid
                          anchors.fill: parent
                          columns: baseFieldSize
                          rows: baseFieldSize

                          Repeater {
                              id: repeaterComp
                              delegate: Item {
                                  width: baseWidthHeight
                                  height: baseWidthHeight

                                  Image {
                                      anchors.fill: parent
                                      source: model.backgroundURL
                                  }

                                  Text {
                                      anchors.centerIn: parent
                                      text: model.text
                                  }
                              }
                          }
                      }
                 }
            }
        }

        Column {
            rotation: settings.settingRotationFieldBottom
            transformOrigin: Item.Center
            spacing: Theme.paddingMedium
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                text: username + qsTr(" (steps ") + dataModel.countStepsUser + qsTr(")")
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeSmall
            }

            Grid {
                spacing: spacingGrid
                height: spacingGrid * baseFieldSize + baseWidthHeight * (baseFieldSize + 1)
                columns: 2

                Rectangle {
                      width: baseWidthHeight
                      height: baseWidthHeight
                      color: "darkRed";
                }

                FieldTableLitters {

                }

                FieldTableDigits{

                }

                Item {
                      width: baseWidthHeight * baseFieldSize
                      height: baseWidthHeight * baseFieldSize

                      Grid {
                          spacing: spacingGrid
                          anchors.fill: parent
                          columns: baseFieldSize
                          rows: baseFieldSize

                          Repeater {
                              id: repeaterUser
                              delegate: Item {
                                  width: baseWidthHeight
                                  height: baseWidthHeight

                                  Image {
                                      anchors.fill: parent
                                      source: model.backgroundURL
                                  }

                                  Text {
                                      anchors.centerIn: parent
                                      text: model.text
                                  }

                                  MouseArea {
                                      anchors.fill: parent
                                      onClicked: {
                                          dataModel.shotCellUser(model.index);
                                      }
                                      onPressAndHold: {
                                          dataModel.putOrRemoveMarkCellUser(model.index);
                                      }
                                  }
                              }
                          }
                      }
                 }
            }
        }
    }

    Component.onCompleted: {
        var statusGame = "game"
        DB.dbInsertRowGameStatus(typeGame, level, quantityFoxes, baseFieldSize, statusGame)
        initDataModel()
        repeaterComp.model = dataModel.dataComp
        repeaterUser.model = dataModel.dataUser
    }

    function initDataModel() {
        dataModel.baseTableSize = baseFieldSize
        dataModel.numberFoxes = quantityFoxes
        dataModel.speedStepComp = speedStepComputer
        dataModel.levelGame = level
        dataModel.createData()
        restoreGame()
    }

    function restoreGame() {
        dataModel.flagLockedTables = true
        var numberCellCompFoxes = DB.dbGetFoxesFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "Comp")
        dataModel.addFoxesComp(numberCellCompFoxes)
        if (settings.settingSavingGames == "false") {
            dataModel.initFoxesUser()
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "Comp")
        } else {
            if(DB.dbExistsFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User") == false) {
                dataModel.initFoxesUser()
            } else {
                restoreStepsGame()
            }
        }
        dataModel.flagLockedTables = false
    }

    function restoreStepsGame() {
        var numberCellUserFoxes = DB.dbGetFoxesFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User")
        dataModel.addFoxesUser(numberCellUserFoxes)
        var stepRestoreGame = DB.dbGetStepGameLocationGameSave(level, quantityFoxes, baseFieldSize)
        var numberRows = stepRestoreGame.length
        for (var i = 0; i < numberRows; i++) {
            if (stepRestoreGame[i].field == "Comp") {
                dataModel.shotCellCompGameRestore(stepRestoreGame[i].index)
            }
            if (stepRestoreGame[i].field == "User") {
                dataModel.shotCellUserGameRestore(stepRestoreGame[i].index)
            }
        }
        if (numberRows > 0 && stepRestoreGame[numberRows-1].field == "User" && stepRestoreGame[numberRows-1].fox == 0) {
            dataModel.shotCellComp();
        }
    }
}

