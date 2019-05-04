import QtQuick 2.0
import Sailfish.Silica 1.0
import QtMultimedia 5.6
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB
import TablesPractice 1.0
import "components/cells_field"

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property int spacingGrid: 1
    property int baseFieldSize: settings.settingBaseTableSize
    property int quantityFoxes: settings.settingNumberFoxes
    property int baseWidthHeight: page.width * (9 / baseFieldSize) / 15
    property int level: 0
    property string field: "Practice"
    property string tableName: "gamePracticeStatistics"

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

        TablesPractice {
            id: dataModelPractice
            baseTableSize: baseFieldSize
            numberFoxes: quantityFoxes
            onAddFoxUser: {
                if (settings.settingSavingGames == "true") {
                    var fox = 1
                    var shot = 0
                    DB.dbInsertRowLocationGameSave(level, quantityFoxes, baseFieldSize, field, index, fox, shot)
                }
            }
            onShotUser: {
                soundEffect.play()
                if (settings.settingSavingGames == "true") {
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
                        stepsUser: countStepsUser,
                    }
                    DB.dbInsertRowGameStatistics(tableName, JSON.stringify(obj))
                }
                DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, field)
                pageStack.replace(Qt.resolvedUrl("WinGamePracticePage.qml"))
            }
        }

        Label {
            width:column.width - Theme.paddingLarge * 2
            horizontalAlignment: Text.AlignJustify
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WordWrap
            text: qsTr(" Min steps ")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeMedium
        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr(" (steps ") + dataModelPractice.countStepsUser + qsTr(")")
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
                          model: dataModelPractice.dataUser
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
                                      dataModelPractice.shotCellUser(model.index);
                                  }
                                  onPressAndHold: {
                                      dataModelPractice.putOrRemoveMarkCellUser(model.index);
                                  }
                              }
                          }
                      }
                  }
             }
        }
    }

    Component.onCompleted: {
        restoreGame()
    }

    function restoreGame() {
        dataModelPractice.flagLockedTables = true
        if (settings.settingSavingGames == "false") {
            dataModelPractice.initFoxesUser()
        } else {
            if(DB.dbExistsFieldLocationGameSave(level, quantityFoxes, baseFieldSize, field)) {
                restoreStepsGame()
            } else {
                dataModelPractice.initFoxesUser()
            }
        }
        dataModelPractice.flagLockedTables = false
    }

    function restoreStepsGame() {
        var numberCellUserFoxes = DB.dbGetFoxesFieldLocationGameSave(level, quantityFoxes, baseFieldSize, field)
        dataModelPractice.addFoxesUser(numberCellUserFoxes)
        var stepRestoreGame = DB.dbGetStepGameLocationGameSave(level, quantityFoxes, baseFieldSize)
        var numberRows = stepRestoreGame.length
        for (var i = 0; i < numberRows; i++) {
            if (stepRestoreGame[i].field == "Practice") {
                dataModelPractice.shotCellUserGameSave(stepRestoreGame[i].index)
            }
        }
    }
}
