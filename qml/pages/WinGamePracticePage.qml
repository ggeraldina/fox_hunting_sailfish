import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property string username: settings.settingUserName

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

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("The game is over.")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeLarge
        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Congratulate!")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeLarge
        }

        Label {
            id: labelSteps
            visible: false
            anchors.horizontalCenter: parent.horizontalCenter
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeLarge
        }

        AnimatedImage {
            anchors.horizontalCenter: parent.horizontalCenter
            id: animation
            source: "qrc:/image/salute.gif"
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("New game")
            onClicked: pageStack.replace(Qt.resolvedUrl("GamePracticePage.qml"))
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Menu")
            onClicked: pageStack.navigateBack()
        }

        Component.onCompleted: {
            if (settings.settingSavingStatistics == "true") {
                var countSteps = DB.dbCountStepsGamePracticeStatistics()
                labelSteps.visible = true
                labelSteps.text = username + "! " +
                        qsTr("You made steps - ") +
                        countSteps
            }
        }
    }
}

