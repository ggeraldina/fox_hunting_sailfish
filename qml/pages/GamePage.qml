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
    property int spacingGrid: 1    
    property int baseFieldSize: settings.settingBaseTableSize
    property int quantityFoxes: settings.settingNumberFoxes
    property int speedStepComputer: settings.settingSpeedStepComp
    property int level: settings.settingLevel
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

        TablesCompUser {
            id: dataModel
            baseTableSize: baseFieldSize
            numberFoxes: quantityFoxes
            speedStepComp: speedStepComputer
            levelGame: level
            onAddFoxUser: {
                var field = "User"
                var fox = 1
                var shot = 0
                DB.dbInsertRowLocationGameSave(level, quantityFoxes, baseFieldSize, field, index, fox, shot)
//                DB.dbPrintLocationGameSave()
            }
            onShotUser: {
                soundEffect.play()
                var field = "User"
                var fox = 0
                var shot = 1
                DB.dbInsertRowLocationGameSave(level, quantityFoxes, baseFieldSize, field, index, fox, shot)
//                DB.dbPrintLocationGameSave()
            }
            onShotComp: {
                soundEffect.play()
                var field = "Comp"
                var fox = 0
                var shot = 1
                DB.dbInsertRowLocationGameSave(level, quantityFoxes, baseFieldSize, field, index, fox, shot)
//                DB.dbPrintLocationGameSave()
            }
            onWinUser: {
                var obj = { date: new Date(),
                    sizeField: baseFieldSize,
                    countFoxes: quantityFoxes,
                    winner: "You",
                    level: level,
                    stepsComp: countStepsComp,
                    stepsUser: countStepsUser,
                }
                DB.dbInsertRowGameStatistics(tableName, JSON.stringify(obj))
                DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User")
                DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "Comp")
                pageStack.replace(Qt.resolvedUrl("WinGamePage.qml"))
            }
            onWinComp: {
                var obj = { date: new Date(),
                    sizeField: baseFieldSize,
                    countFoxes: quantityFoxes,
                    winner: "I",
                    level: level,
                    stepsComp: countStepsComp,
                    stepsUser: countStepsUser,
                }
                DB.dbInsertRowGameStatistics(tableName, JSON.stringify(obj))
                DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User")
                DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "Comp")
                pageStack.replace(Qt.resolvedUrl("LoseGamePage.qml"))
            }
        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("I") +
                  qsTr(" (steps ") + dataModel.countStepsComp + qsTr(")")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeSmall
        }

        Grid {
            id: fieldTop
            spacing: spacingGrid
            x: page.width / 2 - width / 2 - spacingGrid * baseFieldSize / 2
            height: spacingGrid * baseFieldSize + baseWidthHeight * (baseFieldSize + 1)
            columns: 2

            Rectangle {
                  id: item
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
                      id: fieldTopFox
                      spacing: spacingGrid
                      anchors.fill: parent
                      columns: baseFieldSize
                      rows: baseFieldSize

                      Repeater {
                          model: dataModel.dataComp
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

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("You") +
                  qsTr(" (steps ") + dataModel.countStepsUser + qsTr(")")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeSmall
        }

        Grid {
            id: fieldBottom
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
                      id: fieldBottomFox
                      spacing: spacingGrid
                      anchors.fill: parent
                      columns: baseFieldSize
                      rows: baseFieldSize

                      Repeater {
                          model: dataModel.dataUser
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

    Component.onCompleted: {
        DB.dbInitGameStatistics(tableName)
        var numberCellCompFoxes = DB.dbGetFoxesFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "Comp")
        dataModel.addFoxesComp(numberCellCompFoxes)
        if(DB.dbExistsFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User") == false) {
            dataModel.initFoxesUser()
        } else {
            var numberCellUserFoxes = DB.dbGetFoxesFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User")
            dataModel.addFoxesUser(numberCellUserFoxes)
            var stepRestoreGame = DB.dbGetStepGameLocationGameSave(level, quantityFoxes, baseFieldSize)
            for (var i = 0; i < stepRestoreGame.length; i++) {
//                console.log(i + " cell.index " + stepRestoreGame[i].index + " " + stepRestoreGame[i].field)
                if (stepRestoreGame[i].field == "Comp") {
//                    console.log("comp cell.index " + stepRestoreGame[i].index)
                    dataModel.shotCellCompGameSave(stepRestoreGame[i].index)
                }
                if (stepRestoreGame[i].field == "User") {
//                    console.log("user cell.index " + stepRestoreGame[i].index)
                    dataModel.shotCellUserGameSave(stepRestoreGame[i].index)
                }
            }
        }
//        console.log("create game page")
//        console.log(numberCellCompFoxes)
//        console.log(numberCellUserFoxes)
//        DB.dbPrintLocationGameSave()
    }
}

