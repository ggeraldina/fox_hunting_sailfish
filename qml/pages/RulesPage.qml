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
                title: qsTr("Rules of the game")
            }

            ExpandingSectionGroup {
                ExpandingSection {
                    title: qsTr("Order of play")
                    content.sourceComponent: Column {
                        Text {
                            width:column.width - Theme.paddingLarge * 2
                            horizontalAlignment: Text.AlignJustify
                            anchors.horizontalCenter: parent.horizontalCenter
                            wrapMode: Text.WordWrap
                            color: Theme.highlightColor
                            font.pixelSize: Theme.fontSizeMedium
                            text: qsTr("order of play")
                        }
                    }
                }

                ExpandingSection {
                    title: qsTr("Feature of the game")
                    content.sourceComponent: Column {
                        Text {
                            width:column.width - Theme.paddingLarge * 2
                            horizontalAlignment: Text.AlignJustify
                            anchors.horizontalCenter: parent.horizontalCenter
                            wrapMode: Text.WordWrap
                            color: Theme.highlightColor
                            font.pixelSize: Theme.fontSizeMedium
                            text: qsTr("feature of the game")
                        }
                    }
                }

                ExpandingSection {
                    title: qsTr("Functionality of the program")
                    content.sourceComponent: Column {
                        Text {
                            width:column.width - Theme.paddingLarge * 2
                            horizontalAlignment: Text.AlignJustify
                            anchors.horizontalCenter: parent.horizontalCenter
                            wrapMode: Text.WordWrap
                            color: Theme.highlightColor
                            font.pixelSize: Theme.fontSizeMedium
                            text: qsTr("functionality of the program")
                        }
                    }
                }
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
