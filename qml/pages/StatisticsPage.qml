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
        }

        Column {
            id: column
            width: flickable.width
            spacing: Theme.paddingMedium

            Item {
                width: column.width
                height: headerPage.height

                PageHeader {
                    id: headerPage
                    title: qsTr("Game's statistics")
                    anchors.right: buttonDeleteStatistics.left
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
                            height: 300
                            id: grid
                            spacing: Theme.paddingMedium
                            columns: 2
                            rows: 5

                            Text {
                                id: textDate
                                text: qsTr("Date ")
                                color: Theme.highlightColor
                            }

                            Text {
                                id: textTime
                                text: qsTr("Time ")
                                color: Theme.highlightColor
                            }

                            Text {
                                id: textSizeField
                                text: qsTr("Size field ")
                                color: Theme.highlightColor
                            }

                            Text {
                                id: textNumberFoxes
                                text: qsTr("Foxes ")
                                color: Theme.highlightColor
                            }

                            Text {
                                id: textWinner
                                text: qsTr("Winner ")
                                color: Theme.highlightColor
                            }

                            Text {
                                id: textLevelGame
                                text: qsTr("Level ")
                                color: Theme.highlightColor
                            }

                            Text {
                                id: textStepsComp
                                text: qsTr("Steps comp ")
                                color: Theme.highlightColor
                            }

                            Text {
                                id: textTimeComp
                                text: qsTr("Time comp ")
                                color: Theme.highlightColor
                            }

                            Text {
                                id: textStepsUser
                                text: qsTr("Steps user ")
                                color: Theme.highlightColor
                            }

                            Text {
                                id: textTimeUser
                                text: qsTr("Time user ")
                                color: Theme.highlightColor
                            }
                        }

                        Component.onCompleted: {
                            var obj = JSON.parse(model.dataJSON)
                            var date = new Date(obj.date)
                            textDate.text += date.toDateString()
                            textTime.text += date.toTimeString()
                            textSizeField.text += (obj.sizeField + "×" + obj.sizeField)
                            textNumberFoxes.text += obj.countFoxes
                            textWinner.text += obj.winner
                            textLevelGame.text += obj.level
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
