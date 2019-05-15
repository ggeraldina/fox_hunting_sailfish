import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property int levelDefault: 0
    property string winner: ""
    property string namePlayer1: settings.settingUserName
    property string namePlayer2: settings.settingUserOpponentName

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
            text: qsTr("Winner ") + winner
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeLarge
        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Congratulate!")
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
            onClicked: pageStack.replace(Qt.resolvedUrl("LocationFoxesPage.qml"),
                                         { typeGame: "UserUser",
                                           level: levelDefault,
                                           field: "User1",
                                           fieldOpponent: "User0",
                                           nextPage: "LocationFoxesPage.qml",
                                           namePlayer1: namePlayer1,
                                           namePlayer2: namePlayer2})
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Menu")
            onClicked: pageStack.navigateBack()
        }
    }
}
