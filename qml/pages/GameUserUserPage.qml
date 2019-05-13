import QtQuick 2.0
import Sailfish.Silica 1.0
import QtMultimedia 5.6
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB
import TablesUserUser 1.0
import "components/cells_field"

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property string typeGame: "UserUser"
    property string namePlayer1: settings.settingUserName
    property string namePlayer2: settings.settingUserOpponentName
    property int spacingGrid: 1
    property int baseFieldSize: settings.settingBaseTableSize
    property int quantityFoxes: settings.settingNumberFoxes
    property int baseWidthHeight: page.width * (9 / baseFieldSize) / 15
    property int level: 0
    property string tableName: "gameUserUserStatistics"


    Connections {
        target: settings
    }

    SoundEffect {
        id: soundEffect
        source: "qrc:/soundeffects/shot.wav"
        volume : settings.settingVolumeEffects
        loops : 1
    }

    TablesUserUser {
        id: dataModelUserUser
        onShotUserOpponent: {
            soundEffect.play()
            if (settings.settingSavingGames == "true") {
                var field = "User0"
                var fox = 0
                var shot = 1
                DB.dbInsertRowLocationGameSave(level, quantityFoxes, baseFieldSize, field, index, fox, shot)
            }
        }
        onShotUser: {
            soundEffect.play()
            if (settings.settingSavingGames == "true") {
                var field = "User1"
                var fox = 0
                var shot = 1
                DB.dbInsertRowLocationGameSave(level, quantityFoxes, baseFieldSize, field, index, fox, shot)
            }
        }
        onWinUserOpponent: {
            if (settings.settingSavingStatistics == "true") {
                var obj = { date: new Date(),
                    sizeField: baseFieldSize,
                    countFoxes: quantityFoxes,
                    winner: namePlayer1,
                    level: level,
                    stepsUserOpponent: countStepsUserOpponent,
                    stepsUser: countStepsUser,
                }
                DB.dbInsertRowGameStatistics(tableName, JSON.stringify(obj))
            }
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User0")
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User1")
            var statusGame = "new"
            DB.dbInsertRowGameStatus(typeGame, level, quantityFoxes, baseFieldSize, statusGame)
            pageStack.replace(Qt.resolvedUrl("WinGameUserUserPage.qml"), {winner : namePlayer1})
        }
        onWinUser: {
            if (settings.settingSavingStatistics == "true") {
                var obj = { date: new Date(),
                    sizeField: baseFieldSize,
                    countFoxes: quantityFoxes,
                    winner: namePlayer2,
                    level: level,
                    stepsUserOpponent: countStepsUserOpponent,
                    stepsUser: countStepsUser,
                }
                DB.dbInsertRowGameStatistics(tableName, JSON.stringify(obj))
            }
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User0")
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User1")
            var statusGame = "new"
            DB.dbInsertRowGameStatus(typeGame, level, quantityFoxes, baseFieldSize, statusGame)
            pageStack.replace(Qt.resolvedUrl("WinGameUserUserPage.qml"), {winner: namePlayer2})
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

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: namePlayer1 +  qsTr(" (steps ") + dataModelUserUser.countStepsUserOpponent + qsTr(")")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeSmall
        }

        Grid {
            spacing: spacingGrid
            x: page.width / 2 - width / 2 - spacingGrid * baseFieldSize / 2
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
                          id: repeaterUser0
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
                                      dataModelUserUser.shotCellUserOpponent(model.index);
                                  }
                                  onPressAndHold: {
                                      dataModelUserUser.putOrRemoveMarkCellUserOpponent(model.index);
                                  }
                              }
                          }
                      }
                  }
             }
        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: namePlayer2 + qsTr(" (steps ") + dataModelUserUser.countStepsUser + qsTr(")")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeSmall
        }

        Grid {
            spacing: spacingGrid
            x: page.width / 2 - width / 2 - spacingGrid * baseFieldSize / 2
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
                          id: repeaterUser1
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
                                      dataModelUserUser.shotCellUser(model.index);
                                  }
                                  onPressAndHold: {
                                      dataModelUserUser.putOrRemoveMarkCellUser(model.index);
                                  }
                              }
                          }
                      }
                  }
             }
        }
    }

    Component.onCompleted: {
//        DB.dbPrintTable("locationGameSave")
        var statusGame = "game"
        DB.dbInsertRowGameStatus(typeGame, level, quantityFoxes, baseFieldSize, statusGame)
        initDataModelUserUser()
        repeaterUser0.model = dataModelUserUser.dataUserOpponent
        repeaterUser1.model = dataModelUserUser.dataUser
    }

    function initDataModelUserUser() {
        dataModelUserUser.baseTableSize = baseFieldSize
        dataModelUserUser.numberFoxes = quantityFoxes
        dataModelUserUser.createData()
        restoreGame()
    }

    function restoreGame() {
        dataModelUserUser.flagLockedTablesOpponent = true
        dataModelUserUser.flagLockedTables = true
        var numberCellUserOpponentFoxes = DB.dbGetFoxesFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User0")
        var numberCellUserFoxes = DB.dbGetFoxesFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User1")
        dataModelUserUser.addFoxesUserOpponent(numberCellUserOpponentFoxes)
        dataModelUserUser.addFoxesUser(numberCellUserFoxes)
        if (settings.settingSavingGames == "false") {
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User0")
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User1")
        } else {
            restoreStepsGame()
        }
    }

    function restoreStepsGame() {
        var stepRestoreGame = DB.dbGetStepGameLocationGameSave(level, quantityFoxes, baseFieldSize)
        var numberRows = stepRestoreGame.length
        for (var i = 0; i < numberRows; i++) {
            if (stepRestoreGame[i].field == "User0") {
                dataModelUserUser.shotCellUserOpponentGameRestore(stepRestoreGame[i].index)
            }
            if (stepRestoreGame[i].field == "User1") {
                dataModelUserUser.shotCellUserGameRestore(stepRestoreGame[i].index)
            }
        }
        if (numberRows > 0 && stepRestoreGame[numberRows-1].field == "User0" && stepRestoreGame[numberRows-1].fox == 0) {
            dataModelUserUser.flagLockedTables = false
            return
        }
        dataModelUserUser.flagLockedTablesOpponent = false
    }

}
