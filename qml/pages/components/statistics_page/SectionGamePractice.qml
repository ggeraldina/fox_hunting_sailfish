import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB

ExpandingSection {
    title: qsTr("Game (practice)")
    content.sourceComponent: Column {
        Text {
            id: textNoData
            text: qsTr("No data")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeSmall
            anchors.horizontalCenter: parent.horizontalCenter
            visible: listModelPractice.count == 0 ? true : false
        }
        Repeater {
            model: listModelPractice
            delegate: Column {
                anchors.horizontalCenter: parent.horizontalCenter
                Label {
                    id: labelPracticeName
                    anchors.right: parent.right
                    text: qsTr("")
                    color: Theme.highlightColor
                    font.pixelSize: Theme.fontSizeTiny
                }
                Column {
                    width: page.width - 40
                    height: (Theme.paddingMedium + Theme.fontSizeSmall) * 5
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: Theme.paddingMedium
                    Text {
                        id: textPracticeWinner
                        text: qsTr("Winner ")
                        color: Theme.highlightColor
                        font.pixelSize: Theme.fontSizeSmall
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Text {
                        id: textPracticeStepsUser
                        text: qsTr("Steps user ")
                        color: Theme.highlightColor
                        font.pixelSize: Theme.fontSizeSmall
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Text {
                        id: textPracticeSizeField
                        text: qsTr("Size field ")
                        color: Theme.highlightColor
                        font.pixelSize: Theme.fontSizeSmall
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Text {
                       id: textPracticeNumberFoxes
                       text: qsTr("Foxes ")
                       color: Theme.highlightColor
                       font.pixelSize: Theme.fontSizeSmall
                       anchors.horizontalCenter: parent.horizontalCenter
                   }
                }
                Component.onCompleted: {
                    var obj = JSON.parse(model.dataJSON)
                    var date = new Date(obj.date)
                    labelPracticeName.text += date.toDateString() + ", " + date.toTimeString()
                    textPracticeSizeField.text += (obj.sizeField + "×" + obj.sizeField)
                    textPracticeNumberFoxes.text += obj.countFoxes
                    textPracticeStepsUser.text += obj.stepsUser
                    textPracticeWinner.text += obj.winner
                }
            }
        }
    }
}
