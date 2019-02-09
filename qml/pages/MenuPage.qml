import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait

    SilicaListView {
        id: listView
        anchors.fill: parent
        header: PageHeader {
            id: headerPage
            title: qsTr("Menu")
        }

        model: ListModel {
            ListElement {
                page: "GamePage.qml"
                title: qsTr("New game")
                section: qsTr("Game")
            }
            ListElement {
                page: "RulesPage.qml"
                title: qsTr("Game's rules")
                section: qsTr("Game")
            }
            ListElement {
                page: "StatisticsPage.qml"
                title: qsTr("Game's statistics")
                section: qsTr("Game")
            }
            ListElement {
                page: "SettingsPage.qml"
                title: qsTr("Game's settings")
                section: qsTr("Settings")
            }
            ListElement {
                page: ""
                title: qsTr("Select language")
                section: qsTr("Settings")
            }
        }

        section {
            property: 'section'
            delegate: SectionHeader {
                text: section
            }
        }

        delegate: BackgroundItem {
            width: listView.width
            Label {
                text: model.title
                color: highlighted ? Theme.highlightColor : Theme.primaryColor
                anchors.verticalCenter: parent.verticalCenter
                x: Theme.horizontalPageMargin
            }
            onClicked: {
                if (page !== "") {
                    pageStack.push(Qt.resolvedUrl(page))
                }
                else {
                   pageStack.navigateBack()
                }
            }
        }
        VerticalScrollDecorator {}
    }
}
