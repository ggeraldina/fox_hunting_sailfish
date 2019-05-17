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

            BackgroundItem {
                id: itemVariants
                width: column.width
                Label {
                    text: qsTr("Variants of the game")
                    color: itemVariants.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("rulesPages/VariantsGamePage.qml"))
                }
            }

            BackgroundItem {
                id: itemOnePlayer
                width: column.width
                Label {
                    text: qsTr("Order of play (One player)")
                    color: itemOnePlayer.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("rulesPages/OnePlayerPage.qml"))
                }
            }

            BackgroundItem {
                id: itemTwoPlayer
                width: column.width
                Label {
                    text: qsTr("Order of play")
                    color: itemTwoPlayer.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("rulesPages/TwoPlayersPage.qml"))
                }
            }

            BackgroundItem {
                id: itemFeatureGame
                width: column.width
                Label {
                    text: qsTr("Feature of the game")
                    color: itemFeatureGame.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("rulesPages/FeatureGamePage.qml"))
                }
            }

            BackgroundItem {
                id: itemFunctionalityGame
                width: column.width
                Label {
                    text: qsTr("Functionality of the program")
                    color: itemFunctionalityGame.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("rulesPages/FunctionalityGamePage.qml"))
                }
            }
        }
        VerticalScrollDecorator { }
    }
}
