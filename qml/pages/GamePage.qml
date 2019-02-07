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
    property int baseFieldSize: settings.settingBaseTableSize || 6
    property int quantityFoxes: settings.settingNumberFoxes || 2
    property int speedStepComputer: settings.settingSpeedStepComp || 1000    
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
            font.pixelSize: Theme.fontSizeSmall
        }

        TablesCompUser {
            id: dataModel
            baseTableSize: baseFieldSize
            numberFoxes: quantityFoxes
            speedStepComp: speedStepComputer
            onShotUser: soundEffect.play()
            onShotComp: soundEffect.play()
            onWinUser: {
                var obj = { date: new Date(),
                    winner: "user",
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
                    winner: "comp",
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
            color: "white"
            font.pixelSize: Theme.fontSizeMedium
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

            Rectangle {
                  width: baseWidthHeight * baseFieldSize
                  height: baseWidthHeight * baseFieldSize
                  color: "transparent";

                  Grid {
                      id: fieldTopFox
                      spacing: spacingGrid
                      anchors.fill: parent
                      columns: baseFieldSize
                      rows: baseFieldSize

                      Repeater {
                          model: dataModel.dataComp
                          delegate: Rectangle {
                                      width: baseWidthHeight
                                      height: baseWidthHeight
                                      color: "transparent"

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
            color: "white"
            font.pixelSize: Theme.fontSizeMedium
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

            Rectangle {
                  width: baseWidthHeight * baseFieldSize
                  height: baseWidthHeight * baseFieldSize
                  color: "transparent";

                  Grid {
                      id: fieldBottomFox
                      spacing: spacingGrid
                      anchors.fill: parent
                      columns: baseFieldSize
                      rows: baseFieldSize

                      Repeater {
                          model: dataModel.dataUser
                          delegate: Rectangle {
                                      width: baseWidthHeight
                                      height: baseWidthHeight
                                      color: "transparent"

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

