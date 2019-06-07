import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait

    PageHeader {
        id: headerPage
        title: qsTr("About program")
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
            text: qsTr("Fox hunting")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeLarge
        }

        Label {
            anchors {
                left: parent.left
                leftMargin: Theme.paddingLarge
            }
            text: qsTr("Version: ") + ("1.2")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeMedium
        }

        Label {
            anchors {
                left: parent.left
                leftMargin: Theme.paddingLarge
            }
            text: qsTr("© 2019")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeMedium
        }

        Label {
            anchors {
                left: parent.left
                leftMargin: Theme.paddingLarge
            }
            text: qsTr("Author: Geraldina")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeMedium
        }

        Text {
            width:column.width - Theme.paddingLarge * 2
            horizontalAlignment: Text.AlignJustify
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WordWrap
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeMedium
            text: qsTr("Please send all your suggestions and advice to e-mail: ggeraldina@yandex.ru")
        }
    }
}
