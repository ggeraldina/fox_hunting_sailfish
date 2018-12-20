import QtQuick 2.0
import Sailfish.Silica 1.0
import TablesCompUser 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property int spacingGrid: 1
    property int baseWidthHeight: page.width / 15

    PageHeader {
        id: headerPage
        title: qsTr("Fox hunting")
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


        TablesCompUser {
            id: dataModel
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            height: baseWidthHeight
            text: qsTr("Computer")
            color: "white"
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
                  width: baseWidthHeight * 9 // - spacingGrid * 9
                  height: baseWidthHeight * 9 // - spacingGrid * 9
                  color: "transparent";

                  Grid {
                      id: fieldTopFox
                      spacing: spacingGrid
                      anchors.fill: parent
                      columns: 9
                      rows: 9

                      Repeater {
                          model: dataModel.dataComp
                          delegate: Rectangle {
                                      width: baseWidthHeight // - spacingGrid
                                      height: baseWidthHeight // - spacingGrid
                                      color: "lightGreen"

                                      Text {
                                          anchors.centerIn: parent
                                          text: model.text
                                      }
                                      MouseArea {
                                          anchors.fill: parent
                                          onClicked: { console.log("hi!" + model.index)}
                                      }
                                  }
                      }
                  }
             }
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            height: baseWidthHeight
            text: qsTr("You")
            color: "white"
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
                  width: baseWidthHeight * 9 // - spacingGrid * 9
                  height: baseWidthHeight * 9 // - spacingGrid * 9
                  color: "transparent";

                  Grid {
                      id: fieldBottomFox
                      spacing: spacingGrid
                      anchors.fill: parent
                      columns: 9
                      rows: 9

                      Repeater {
                          model: dataModel.dataUser
                          delegate: Rectangle {
                                      width: baseWidthHeight // - spacingGrid
                                      height: baseWidthHeight //  - spacingGrid
                                      color: "lightGreen"

                                      Text {
                                          anchors.centerIn: parent
                                          text: model.text
                                      }
                                      MouseArea {
                                          anchors.fill: parent
                                          onClicked: { console.log("hi2!" + model.index)}
                                      }
                                  }
                      }
                  }
             }
        }
    }
}
