import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait

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
            text: qsTr("Menu")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeLarge
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "New game"
            onClicked: pageStack.push(Qt.resolvedUrl("GamePage.qml"))
        }
    }
}
