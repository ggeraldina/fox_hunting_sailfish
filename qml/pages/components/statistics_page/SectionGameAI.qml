import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB

ExpandingSection {
    title: qsTr("Game with AI")
    content.sourceComponent: Column {
        Text {
            id: textNoData
            text: qsTr("No data")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeSmall
            anchors.horizontalCenter: parent.horizontalCenter
            visible: listModel.count == 0 ? true : false
        }
        Repeater {
            model: listModel
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
                    height: (Theme.paddingMedium + Theme.fontSizeSmall) * 8
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
                    textWinner.text += obj.winner
                    textLevelGame.text += obj.level
                    textStepsComp.text += obj.stepsComp
                    textStepsUser.text += obj.stepsUser
                }
            }
        }
    }
}
