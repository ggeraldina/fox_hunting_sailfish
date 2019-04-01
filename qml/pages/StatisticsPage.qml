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
                            id: labelName
                            anchors.right: parent.right
                            text: qsTr("")
                            color: Theme.highlightColor
                            font.pixelSize: Theme.fontSizeTiny
                        }

                        Column {
                            width: page.width - 40
                            height: (Theme.paddingMedium + Theme.fontSizeSmall) * (6 + 1)
                            anchors.horizontalCenter: parent.horizontalCenter
                            spacing: Theme.paddingMedium

                            Text {
                                id: textWinner
                                text: qsTr("Winner ")
                                color: Theme.highlightColor
                                font.pixelSize: Theme.fontSizeSmall
                                anchors.horizontalCenter: parent.horizontalCenter
                            }                            

                            Text {
                                id: textLevelGame
                                text: qsTr("Level ")
                                color: Theme.highlightColor
                                font.pixelSize: Theme.fontSizeSmall
                                anchors.horizontalCenter: parent.horizontalCenter
                            }

                            Text {
                                id: textStepsUser
                                text: qsTr("Steps user ")
                                color: Theme.highlightColor
                                font.pixelSize: Theme.fontSizeSmall
                                anchors.horizontalCenter: parent.horizontalCenter
                            }

                            Text {
                                id: textStepsComp
                                text: qsTr("Steps comp ")
                                color: Theme.highlightColor
                                font.pixelSize: Theme.fontSizeSmall
                                anchors.horizontalCenter: parent.horizontalCenter
                            }

                            Text {
                                id: textSizeField
                                text: qsTr("Size field ")
                                color: Theme.highlightColor
                                font.pixelSize: Theme.fontSizeSmall
                                anchors.horizontalCenter: parent.horizontalCenter
                            }

                            Text {
                               id: textNumberFoxes
                               text: qsTr("Foxes ")
                               color: Theme.highlightColor
                               font.pixelSize: Theme.fontSizeSmall
                               anchors.horizontalCenter: parent.horizontalCenter
                           }
                        }

                        Component.onCompleted: {
                            var obj = JSON.parse(model.dataJSON)
                            var date = new Date(obj.date)
                            labelName.text += date.toDateString() + ", " + date.toTimeString()
                            textSizeField.text += (obj.sizeField + "×" + obj.sizeField)
                            textNumberFoxes.text += obj.countFoxes
                            if (settings.settingLanguage == "-ru") {
                                if (obj.winner == "I") {
                                    textWinner.text += "Противник"
                                }
                                else {
                                    textWinner.text += "Вы"
                                }
                            }
                            else {
                                if (obj.winner == "I") {
                                    textWinner.text += "Opponent"
                                }
                                else {
                                    textWinner.text += "You"
                                }
                            }
                            textLevelGame.text += obj.level
                            textStepsComp.text += obj.stepsComp
                            textStepsUser.text += obj.stepsUser
                        }
                    }
                }
            }
        }

        VerticalScrollDecorator { }
    }
}
