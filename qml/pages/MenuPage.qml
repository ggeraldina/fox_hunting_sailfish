import QtQuick 2.0
import Sailfish.Silica 1.0
import QmlTranslator 1.0

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
            text: qsTr("New game")
            onClicked: pageStack.push(Qt.resolvedUrl("GamePage.qml"))
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Rules game")
            onClicked: pageStack.push(Qt.resolvedUrl("RulesPage.qml"))
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Statistics game")
            onClicked: pageStack.push(Qt.resolvedUrl("StatisticsPage.qml"))
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Settings")
            onClicked: pageStack.push(Qt.resolvedUrl("SettingsPage.qml"))
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Select language")
            onClicked: pageStack.navigateBack()
        }
    }
}
