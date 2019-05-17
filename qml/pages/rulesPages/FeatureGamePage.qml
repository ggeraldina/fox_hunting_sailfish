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
                title: qsTr("Feature of the game")
            }

            Text {
                width:column.width - Theme.paddingLarge * 2
                horizontalAlignment: Text.AlignJustify
                anchors.horizontalCenter: parent.horizontalCenter
                wrapMode: Text.WordWrap
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeMedium
                text: qsTr("feature of the game 1")
            }

            Text {
                width:column.width - Theme.paddingLarge * 2
                horizontalAlignment: Text.AlignJustify
                anchors.horizontalCenter: parent.horizontalCenter
                wrapMode: Text.WordWrap
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeMedium
                text: qsTr("feature of the game 2")
            }

            Text {
                width:column.width - Theme.paddingLarge * 4
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                wrapMode: Text.WordWrap
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeSmall
                text: qsTr("Directions for finding foxes relative to the cell")
            }

            Image {
                anchors.horizontalCenter: parent.horizontalCenter
                fillMode: Image.PreserveAspectFit
                width: sourceSize.width > (column.width - Theme.paddingLarge * 4) ?
                           column.width - Theme.paddingLarge * 4 :
                           sourceSize.width
                height: width
                source: "qrc:/image/rulesGame/cells_location.png"

            }

            Text {
                width:column.width - Theme.paddingLarge * 4
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                wrapMode: Text.WordWrap
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeSmall
                text: qsTr("The digit is the number of foxes around the cell")
            }

            Image {
                anchors.horizontalCenter: parent.horizontalCenter
                fillMode: Image.PreserveAspectFit
                width: sourceSize.width > (column.width - Theme.paddingLarge * 4) ?
                           column.width - Theme.paddingLarge * 4 :
                           sourceSize.width
                height: width
                source: "qrc:/image/rulesGame/cells_locationFoxes.png"
            }

            Text {
                width:column.width - Theme.paddingLarge * 4
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                wrapMode: Text.WordWrap
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeSmall
                text: qsTr("Foxes are not in cells with a dots")
            }

            Image {
                anchors.horizontalCenter: parent.horizontalCenter
                fillMode: Image.PreserveAspectFit
                width: sourceSize.width > (column.width - Theme.paddingLarge * 4) ?
                           column.width - Theme.paddingLarge * 4 :
                           sourceSize.width
                height: width
                source: "qrc:/image/rulesGame/cells_notFox1.png"
            }

            Text {
                width:column.width - Theme.paddingLarge * 2
                horizontalAlignment: Text.AlignJustify
                anchors.horizontalCenter: parent.horizontalCenter
                wrapMode: Text.WordWrap
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeMedium
                text: qsTr("feature of the game 3")
            }

            Text {
                width:column.width - Theme.paddingLarge * 2
                horizontalAlignment: Text.AlignJustify
                anchors.horizontalCenter: parent.horizontalCenter
                wrapMode: Text.WordWrap
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeMedium
                text: qsTr("feature of the game 4")
            }

            Text {
                width:column.width - Theme.paddingLarge * 4
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                wrapMode: Text.WordWrap
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeSmall
                text: qsTr("Foxes are not in cells with a dots")
            }

            Image {
                anchors.horizontalCenter: parent.horizontalCenter
                fillMode: Image.PreserveAspectFit
                width: sourceSize.width > (column.width - Theme.paddingLarge * 4) ?
                           column.width - Theme.paddingLarge * 4 :
                           sourceSize.width
                height: width
                source: "qrc:/image/rulesGame/cells_notFox.png"
            }
        }
    }
}
