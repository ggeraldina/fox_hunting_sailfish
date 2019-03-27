import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait

    PageHeader {
        id: headerPage
        title: qsTr("Menu")
    }

    SilicaFlickable {
        id: flickable
        contentWidth: column.width
        contentHeight: column.height
        anchors.fill: parent
        anchors {
            topMargin: headerPage.height
        }

        Column {
            id: column
            width: flickable.width
            spacing: Theme.paddingMedium

            SectionHeader {
                id: sectionGame
            }

            BackgroundItem {
                id: itemNewGame
                width: column.width
                Label {
                    id: labelNewGame
                    color: itemNewGame.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("GamePage.qml"))
                }
            }


            BackgroundItem {
                id: itemRules
                width: column.width
                Label {
                    id: labelRules
                    color: itemRules.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("RulesPage.qml"))
                }
            }

            BackgroundItem {
                id: itemStatistics
                width: column.width
                Label {
                    id: labelStatistics
                    color: itemStatistics.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("StatisticsPage.qml"))
                }
            }

            SectionHeader {
                id: sectionSettings
            }

            BackgroundItem {
                id: itemSettings
                width: column.width
                Label {
                    id: labelSettings
                    color: itemSettings.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("SettingsPage.qml"))
                }
            }

            ComboBox {
                id: comboBoxLanguage
                width: page.width
                currentIndex: settings.settingLanguage == "-en" ? 0 : 1
                label: qsTr("Language | Язык")

                menu: ContextMenu {
                    MenuItem {
                        text: qsTr("EN")
                        onClicked: {
                            translator.setTranslation("-en")
                            settings.settingLanguage = "-en"
                        }
                    }
                    MenuItem {
                        text: qsTr("RU")
                        onClicked: {
                              translator.setTranslation("-ru")
                              settings.settingLanguage = "-ru"
                        }
                    }
                }
            }
        }

        VerticalScrollDecorator {}
    }

    Connections {
        target: translator
        onLanguageChanged: {
            retranslateUi()
        }
    }

    function retranslateUi() {
        headerPage.title = qsTr("Menu")
        labelNewGame.text = qsTr("New game")
        labelRules.text = qsTr("Game's rules")
        labelStatistics.text = qsTr("Game's statistics")
        labelSettings.text  = qsTr("Game's settings")
        sectionGame.text = qsTr("Game")
        sectionSettings.text = qsTr("Settings")
    }

    Component.onCompleted: {
        retranslateUi();
    }
}
