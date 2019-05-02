import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property int baseFieldSize: settings.settingBaseTableSize
    property int quantityFoxes: settings.settingNumberFoxes
    property int level: settings.settingLevel

    Connections {
        target: translator
        onLanguageChanged: {
            retranslateUi()
        }
    }

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
                    DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User")
                    DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "Comp")
                    pageStack.push(Qt.resolvedUrl("LocationFoxesPage.qml"))
                }
            }

            BackgroundItem {
                id: itemContinueGame
                width: column.width
                Label {
                    id: labelContinueGame
                    color: itemNewGame.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    if (DB.dbExistsFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User") == false) {
                        pageStack.push(Qt.resolvedUrl("LocationFoxesPage.qml"))
                    } else {
                        pageStack.push(Qt.resolvedUrl("GamePage.qml"))
                    }
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

            SectionHeader {
                id: sectionHelp
            }

            BackgroundItem {
                id: itemAbout
                width: column.width
                Label {
                    id: labelAbout
                    color: itemAbout.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
                }
            }
        }        

        VerticalScrollDecorator {}
    }

    onStatusChanged: {
        if (status == PageStatus.Activating) {
//            console.log("activating")
            if (DB.dbExistsFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "Comp") == false) {
                itemContinueGame.visible = false
            } else {
                itemContinueGame.visible = true
            }
//            DB.dbPrintLocationGameSave()
        }
    }

    function retranslateUi() {
        headerPage.title = qsTr("Menu")
        labelNewGame.text = qsTr("New game")
        labelContinueGame.text = qsTr("Continue game")
        labelRules.text = qsTr("Game's rules")
        labelStatistics.text = qsTr("Game's statistics")
        labelSettings.text = qsTr("Game's settings")
        labelAbout.text = qsTr("About program")
        sectionGame.text = qsTr("Game")
        sectionSettings.text = qsTr("Settings")
        sectionHelp.text = qsTr("Help")
    }

    Component.onCompleted: {
        retranslateUi();
    }
}
