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
    property int levelDefault: 0

    Connections {
        target: translator
        onLanguageChanged: {
            retranslateUi()
        }
    }

    SilicaFlickable {
        id: flickable
        contentWidth: column.width
        contentHeight: column.height
        anchors.fill: parent

        Column {
            id: column
            width: flickable.width
            spacing: Theme.paddingMedium

            PageHeader {
                id: headerPage
                title: qsTr("Menu")
            }

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
                    pageStack.push(Qt.resolvedUrl("LocationFoxesPage.qml"),
                                   { level: level,
                                     field: "Comp",
                                     fieldOpponent: "User",
                                     nextPage: "GamePage.qml",
                                     namePlayer: "" })
                }
            }

            BackgroundItem {
                id: itemContinueGame
                width: column.width
                Label {
                    id: labelContinueGame
                    color: itemContinueGame.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    if (DB.dbExistsFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "User") == false) {
                        pageStack.push(Qt.resolvedUrl("LocationFoxesPage.qml"),
                                       { level: level,
                                         field: "Comp",
                                         fieldOpponent: "User",
                                         nextPage: "GamePage.qml",
                                         namePlayer: "" })
                    } else {
                        pageStack.push(Qt.resolvedUrl("GamePage.qml"))
                    }
                }
            }

            BackgroundItem {
                id: itemNewGamePractice
                width: column.width
                Label {
                    id: labelNewGamePractice
                    color: itemNewGamePractice.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    var levelPractice = 0
                    DB.dbDeleteFieldLocationGameSave(levelPractice, quantityFoxes, baseFieldSize, "Practice")
                    pageStack.push(Qt.resolvedUrl("GamePracticePage.qml"))
                }
            }

            BackgroundItem {
                id: itemContinueGamePractice
                width: column.width
                Label {
                    id: labelContinueGamePractice
                    color: itemContinueGamePractice.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("GamePracticePage.qml"))
                }
            }

            BackgroundItem {
                id: itemNewGameUserUser
                width: column.width
                Label {
                    id: labelNewGameUserUser
                    color: itemNewGameUserUser.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    DB.dbDeleteFieldLocationGameSave(levelDefault, quantityFoxes, baseFieldSize, "User0")
                    DB.dbDeleteFieldLocationGameSave(levelDefault, quantityFoxes, baseFieldSize, "User1")
                    pageStack.push(Qt.resolvedUrl("LocationFoxesPage.qml"),
                                   { level: levelDefault,
                                     field: "User1",
                                     fieldOpponent: "User0",
                                     nextPage: "LocationFoxesPage.qml",
                                     namePlayer: "Player 1! " })
                }
            }

            BackgroundItem {
                id: itemContinueGameUserUser
                width: column.width
                Label {
                    id: labelContinueGameUserUser
                    color: itemContinueGameUserUser.highlighted ? Theme.highlightColor : Theme.primaryColor
                    anchors.verticalCenter: parent.verticalCenter
                    x: Theme.horizontalPageMargin
                }
                onClicked: {
                    if (DB.dbExistsFieldLocationGameSave(levelDefault, quantityFoxes, baseFieldSize, "User1") == false) {
                        pageStack.push(Qt.resolvedUrl("LocationFoxesPage.qml"),
                                       { level: levelDefault,
                                         field: "User1",
                                         fieldOpponent: "User0",
                                         nextPage: "LocationFoxesPage.qml",
                                         namePlayer: "Player 1! " })
                    } else {
                        if (DB.dbExistsFieldLocationGameSave(levelDefault, quantityFoxes, baseFieldSize, "User0") == false) {
                            pageStack.push(Qt.resolvedUrl("LocationFoxesPage.qml"),
                                           { level: levelDefault,
                                             field: "User0",
                                             fieldOpponent: "",
                                             nextPage: "GameUserUserPage.qml",
                                             namePlayer: "Player 2! " })
                        } else {
                            pageStack.push(Qt.resolvedUrl("GameUserUserPage.qml"))
                        }
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
            var levelPractice = 0
            if (settings.settingSavingGames == "true") {
                if (DB.dbExistsFieldLocationGameSave(level, quantityFoxes, baseFieldSize, "Comp")) {
                    itemContinueGame.visible = true
                } else {
                    itemContinueGame.visible = false
                }
                if (DB.dbExistsFieldLocationGameSave(levelPractice, quantityFoxes, baseFieldSize, "Practice")) {
                    itemContinueGamePractice.visible = true
                } else {
                    itemContinueGamePractice.visible = false
                }
            } else {
                itemContinueGame.visible = false
                itemContinueGamePractice.visible = false
            }
            if (DB.dbExistsDataTable("gameStatistics")) {
                itemStatistics.visible = true
            } else {
                itemStatistics.visible = false
            }
        }
    }

    function retranslateUi() {
        headerPage.title = qsTr("Menu")
        labelNewGame.text = qsTr("New game")
        labelContinueGame.text = qsTr("Continue game")
        labelNewGamePractice.text = qsTr("New game (practice)")
        labelContinueGamePractice.text = qsTr("Continue game (practice)")
        labelNewGameUserUser.text = qsTr("New game against player")
        labelContinueGameUserUser.text = qsTr("Continue game against player")
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
