import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property string tableName: "gameStatistics"

    Component.onCompleted: {
        DB.dbInit(tableName)
    }

    SilicaFlickable {
        id: flickable
        contentWidth: column.width
        contentHeight: column.height
        anchors {
            top: page.top
            right: page.right
            left: page.left
            bottom: page.bottom
            bottomMargin: 20
        }

        Column {
            id: column
            width: flickable.width
            spacing: Theme.paddingMedium

            PageHeader {
                id: headerPage
                title: qsTr("Fox hunting")
            }

            Label {
                id: labelGameStatistics
                text: qsTr("Game's statistics")
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeLarge
                anchors.horizontalCenter: parent.horizontalCenter
            }

            IconButton {
                id: buttonDeleteStatistics
                anchors.right: parent.right
                // подчеркивание icon.source красным в Qt Creator - это нормально
                icon.source: "image://theme/icon-m-delete"
                onClicked: {
                    DB.dbDeleteAll(tableName)
                }
            }

            Column {
                spacing: Theme.paddingMedium
                width: flickable.width

                Repeater {
                    model: ListModel {
                        id: listModel
                        Component.onCompleted: DB.dbReadAll(tableName)
                    }

                    delegate: Column {
                        anchors.horizontalCenter: parent.horizontalCenter

                        Label {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: model.id
                            color: Theme.highlightColor
                            font.pixelSize: Theme.fontSizeMedium
                        }

                        Grid {
                            width: page.width - 40
                            height: 250
                            id: grid
                            spacing: Theme.paddingMedium
                            columns: 2
                            rows: 4

                            Text {
                                id: textDate
                                text: qsTr("Date ")
                                color: "white"
                            }

                            Text {
                                id: textTime
                                text: qsTr("Time ")
                                color: "white"
                            }

                            Text {
                                id: textWinner
                                text: qsTr("Winner ")
                                color: "white"
                            }

                            Text {
                                text: " "
                            }

                            Text {
                                id: textStepsComp
                                text: qsTr("Steps comp ")
                                color: "white"
                            }

                            Text {
                                id: textTimeComp
                                text: qsTr("Time comp ")
                                color: "white"
                            }

                            Text {
                                id: textStepsUser
                                text: qsTr("Steps user ")
                                color: "white"
                            }

                            Text {
                                id: textTimeUser
                                text: qsTr("Time user ")
                                color: "white"
                            }
                        }

                        Component.onCompleted: {
                            var obj = JSON.parse(model.dataJSON)
                            var date = new Date(obj.date)
                            textDate.text += date.toDateString()
                            textTime.text += date.toTimeString()
                            textWinner.text += obj.winner
                            textStepsComp.text += obj.stepsComp
                            textTimeComp.text += obj.timeComp
                            textStepsUser.text += obj.stepsUser
                            textTimeUser.text += obj.timeUser
                        }
                    }
                }
            }
        }

        VerticalScrollDecorator { }
    }
}
