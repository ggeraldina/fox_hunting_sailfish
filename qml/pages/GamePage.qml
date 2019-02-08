import QtQuick 2.0
import Sailfish.Silica 1.0
import QtMultimedia 5.6
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB
import TablesCompUser 1.0
import QmlSettings 1.0
import "components/cells_field"

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property int spacingGrid: 1
    property int baseWidthHeight: page.width / 14
    property int baseFieldSize: settings.settingBaseTableSize
    property int quantityFoxes: settings.settingNumberFoxes
    property int speedStepComputer: settings.settingSpeedStepComp
    property int level: settings.settingLevel
    property string tableName: "gameStatistics"

    QmlSettings {
        id: settings
    }

    SoundEffect {
        id: soundEffect
        source: "qrc:/soundeffects/shot.wav"
        volume : settings.settingVolumeEffects || 0.0
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

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Steps ") + dataModel.countStepsComp + " | " + dataModel.countStepsUser +
                  qsTr(" and time ") + dataModel.timeGameComp + " | " + dataModel.timeGameUser
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeMedium
        }

        TablesCompUser {
            id: dataModel
            baseTableSize: baseFieldSize
            numberFoxes: quantityFoxes
            speedStepComp: speedStepComputer
            levelGame: level
            onShotUser: soundEffect.play()
            onShotComp: soundEffect.play()
            onWinUser: {
                var obj = { date: new Date(),
                    sizeField: baseFieldSize,
                    countFoxes: quantityFoxes,
                    winner: "user",
                    level: level,
                    stepsComp: countStepsComp,
                    timeComp: timeGameComp,
                    stepsUser: countStepsUser,
                    timeUser: timeGameUser
                }
                DB.dbInsertRow(tableName, JSON.stringify(obj))
                pageStack.replace(Qt.resolvedUrl("WinGamePage.qml"))
            }
            onWinComp: {
                var obj = { date: new Date(),
                    sizeField: baseFieldSize,
                    countFoxes: quantityFoxes,
                    winner: "comp",
                    level: level,
                    stepsComp: countStepsComp,
                    timeComp: timeGameComp,
                    stepsUser: countStepsUser,
                    timeUser: timeGameUser
                }
                DB.dbInsertRow(tableName, JSON.stringify(obj))
                pageStack.replace(Qt.resolvedUrl("LoseGamePage.qml"))
            }
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Computer")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeSmall
        }

        Grid {
            id: fieldTop
            spacing: spacingGrid
            anchors.horizontalCenter: parent.horizontalCenter
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

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("You")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeSmall
        }

        Grid {
            id: fieldBottom
            spacing: spacingGrid
            anchors.horizontalCenter: parent.horizontalCenter
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
}

