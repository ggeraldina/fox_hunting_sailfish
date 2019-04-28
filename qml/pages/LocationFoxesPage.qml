import QtQuick 2.0
import Sailfish.Silica 1.0
import "components/cells_field"
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/DatabaseTableSaveGame.js" as DB

Dialog {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property int spacingGrid: 1
    property int baseFieldSize: settings.settingBaseTableSize
    property int quantityFoxes: settings.settingNumberFoxes
    property int baseWidthHeight: page.width * (9 / baseFieldSize) / 15
    property string tableName: "gameSaveFoxes" + quantityFoxes + "Size" + baseFieldSize

    Connections {
        target: settings
    }

    DialogHeader {
        id: headerPage
        acceptText: qsTr("Ok")
        cancelText: qsTr("Cancel")
    }

    Column {
        id: column
        anchors {
            top: headerPage.bottom
            right: page.right
            left: page.left
            bottom: page.bottom
        }
        spacing: Theme.paddingMedium

        Label {
            text: qsTr("Are you pleased the location of the foxes on the field?")
            width:column.width - Theme.paddingLarge * 2
            horizontalAlignment: Text.AlignJustify
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WordWrap
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeMedium
        }

        Label {
            text: qsTr("You can set the location of the foxes.")
            width:column.width - Theme.paddingLarge * 2
            horizontalAlignment: Text.AlignJustify
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WordWrap
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeMedium
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
                          model: baseFieldSize * baseFieldSize
                          delegate: Item {
                                      width: baseWidthHeight
                                      height: baseWidthHeight

                                      Image {
                                          anchors.fill: parent
                                          source: "qrc:/image/lightGreen.jpg"
                                      }

                                      Text {
                                          anchors.centerIn: parent
                                          text: ""
                                      }
                                  }
                      }
                  }
             }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: qsTr("Randomly")
            }

            IconButton {
                id: buttonDeleteStatistics
                // подчеркивание icon.source красным в Qt Creator - это нормально
                icon.source: "image://theme/icon-m-delete"
                onClicked: {
                    console.log(tableName)
                }
            }
        }
    }

    acceptDestination: Qt.resolvedUrl("GamePage.qml")
    acceptDestinationAction: PageStackAction.Replace

}