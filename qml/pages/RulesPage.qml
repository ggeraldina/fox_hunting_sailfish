import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait

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
                title: qsTr("The rules")
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeMedium
                text: qsTr("Rules of the game 'Fox Hunting'")
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("New game")
                onClicked: pageStack.replace(Qt.resolvedUrl("GamePage.qml"))
            }
        }
        VerticalScrollDecorator { }
    }
}
