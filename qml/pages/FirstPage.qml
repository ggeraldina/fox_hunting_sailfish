import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    allowedOrientations: Orientation.Portrait
    property int spacingGrid: 2

    Column {
        id: column
        anchors.fill: parent
        width: page.width
        height: page.width
        spacing: Theme.paddingLarge
        PageHeader {
            title: qsTr("Fox hunting")
        }

        Grid {
            id: fieldTop
            height: column.height
            spacing: spacingGrid
            anchors.fill: parent
            columns: 2

            Rectangle {
                  id: item
                  width: fieldTop.width / 15
                  height: fieldTop.width / 15
                  color: "darkblue";
                 }

            Rectangle {
                width: item.width * 9 - spacingGrid * 9
                height: item.height
                color: "yellow";
                Grid {
                        id: fieldTopLitters
                        spacing: spacingGrid
                        anchors.fill: parent
                        columns: 9
                        Repeater {
                            model: ListModel {
                                ListElement { name: "А"}
                                ListElement { name: "Б" }
                                ListElement { name: "В" }
                                ListElement { name: "Г" }
                                ListElement { name: "Д" }
                                ListElement { name: "Е" }
                                ListElement { name: "Ж" }
                                ListElement { name: "З" }
                                ListElement { name: "И" }
                            }
                            LittersCell {
                                height: item.height
                                width: fieldTopLitters.width / fieldTopLitters.columns
                                littera: name
                            }
                        }
                    }
                }

            Rectangle {
                width: item.width
                height: item.height * 9 - spacingGrid * 9
                color: "red";
                Grid {
                        id: fieldTopDigits
                        spacing: spacingGrid
                        anchors.fill: parent
                        rows: 9
                        Repeater {
                            model: ListModel {
                                ListElement { name: "1"}
                                ListElement { name: "2" }
                                ListElement { name: "3" }
                                ListElement { name: "4" }
                                ListElement { name: "5" }
                                ListElement { name: "6" }
                                ListElement { name: "7" }
                                ListElement { name: "8" }
                                ListElement { name: "9" }
                            }
                            LittersCell {
                                height: fieldTopDigits.height / fieldTopDigits.rows
                                width: item.width
                                littera: name
                            }
                        }
                    }
                }
            Rectangle {
                  width: item.width * 9  - spacingGrid * 9
                  height: item.height * 9  - spacingGrid * 9
                  color: "orange";

                  Grid {
                          id: fieldTopFox
                          spacing: spacingGrid
                          anchors.fill: parent
                          columns: 9
                          rows: 9
                          Repeater {
                              model: 81
                              FoxCell {
                                  height: item.height  - spacingGrid
                                  width: item.width  - spacingGrid
//                                  id: cell
                              }
                          }
                      }

                 }
        }
    }
}
