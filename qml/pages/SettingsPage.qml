import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property int currentIndexBaseTableSize: settings.settingBaseTableSize - 7
    property int currentIndexNumberFoxes: settings.settingNumberFoxes - 3
    property int currentIndexSpeedStepComp: settings.settingSpeedStepComp / 500 - 1
    property int currentIndexLevel: settings.settingLevel - 1
    property bool currentCheckedSavingGames: settings.settingSavingGames == "true" ? true : false
    property bool currentCheckedSavingStatistics: settings.settingSavingStatistics == "true" ? true : false

    Connections {
            target: translator
    }

    Connections {
            target: settings
            // for default settings
            onSettingBaseTableSizeChanged: comboBoxBaseTableSize.currentIndex = settings.settingBaseTableSize - 7
            onSettingNumberFoxesChanged: comboBoxNumberFoxes.currentIndex = settings.settingNumberFoxes - 3
            onSettingSpeedStepCompChanged: comboBoxSpeedStepComp.currentIndex = settings.settingSpeedStepComp / 500 - 1
            onSettingVolumeEffectsChanged: sliderVolumeEffects.value = settings.settingVolumeEffects
            onSettingLevelChanged: comboBoxLevel.currentIndex = settings.settingLevel - 1
            onSettingSavingGamesChanged: switchSavingGames.checked = settings.settingSavingGames == "true" ? true : false
            onSettingSavingStatisticsChanged: switchSavingStatistics.checked = settings.settingSavingStatistics == "true" ? true : false
    }

    SilicaFlickable {
        id: flickable
        contentWidth: column.width
        contentHeight: column.height
        anchors {
            top: page.top
            right: page.right
            left: page.left
            bottom: page.bottom
        }

        Column {
            id: column
            width: flickable.width
            spacing: Theme.paddingMedium
            Item {
                width: column.width
                height: headerPage.height

                PageHeader {
                    id: headerPage
                    anchors.right: buttonSettings.left
                    title: qsTr("Game's settings")
                }

                IconButton {
                    id: buttonSettings
                    anchors.right: parent.right
                    // подчеркивание icon.source красным в Qt Creator - это нормально
                    icon.source: "image://theme/icon-m-reset"
                    onClicked: {
                        settings.updateToDefaultSettings()
                        sliderVolumeEffects.value = settings.settingVolumeEffects
                    }
                }
            }

            ComboBox {
                id: comboBoxLevel
                width: page.width
                currentIndex: currentIndexLevel
                label: qsTr("Games's level")

                menu: ContextMenu {
                    MenuItem {
                        text: qsTr("1")
                        onClicked: settings.settingLevel = 1
                    }
                    MenuItem {
                        text: qsTr("2")
                        onClicked: settings.settingLevel = 2
                    }
                    MenuItem {
                        text: qsTr("3")
                        onClicked: settings.settingLevel = 3
                    }
                    MenuItem {
                        text: qsTr("4")
                        onClicked: settings.settingLevel = 4
                    }
                    MenuItem {
                        text: qsTr("5")
                        onClicked: settings.settingLevel = 5
                    }
                }
            }

            ComboBox {
                id: comboBoxBaseTableSize
                width: page.width
                currentIndex: currentIndexBaseTableSize
                label: qsTr("Size of games field")

                menu: ContextMenu {
                    MenuItem {
                        text: "7 × 7"
                        onClicked: settings.settingBaseTableSize = 7
                    }
                    MenuItem {
                        text: "8 × 8"
                        onClicked: settings.settingBaseTableSize = 8
                    }
                    MenuItem {
                        text: "9 × 9"
                        onClicked: settings.settingBaseTableSize = 9
                    }
                }
            }

            ComboBox {
                id: comboBoxNumberFoxes
                width: page.width
                currentIndex: currentIndexNumberFoxes
                label: qsTr("Amount foxes")

                menu: ContextMenu {
                    MenuItem {
                        text: "3"
                        onClicked: settings.settingNumberFoxes = 3
                    }
                    MenuItem {
                        text: "4"
                        onClicked: settings.settingNumberFoxes = 4
                    }
                }
            }

            ComboBox {
                id: comboBoxSpeedStepComp
                width: page.width
                currentIndex: currentIndexSpeedStepComp
                label: qsTr("Speed of computer's steps")

                menu: ContextMenu {
                    MenuItem {
                        text: qsTr("0,5 sec")
                        onClicked: settings.settingSpeedStepComp = 500
                    }
                    MenuItem {
                        text: qsTr("1 sec")
                        onClicked: settings.settingSpeedStepComp = 1000
                    }
                }
            }

            Slider {
                id: sliderVolumeEffects
                width: page.width
                label: qsTr("Volume of effects")
                value: settings.settingVolumeEffects
                valueText: value.toFixed(1)
                minimumValue: 0
                maximumValue: 1
                stepSize: 0.1
                on_OldValueChanged: {
                    settings.settingVolumeEffects = value;
                }
            }

            TextSwitch {
                id: switchSavingGames
                text: qsTr("Saving games")
                checked: currentCheckedSavingGames
                onCheckedChanged: {
                    if (checked) {
                        settings.settingSavingGames = "true"
                    } else {
                        settings.settingSavingGames = "false"
                        DB.dbDeleteAllLocationGameSave()
                        DB.dbDeleteAllGameStatus()
                    }
                }
            }

            TextSwitch {
                id: switchSavingStatistics
                text: qsTr("Saving statistics")
                checked: currentCheckedSavingStatistics
                onCheckedChanged: {
                    if (checked) {
                        settings.settingSavingStatistics = "true"
                    } else {
                        settings.settingSavingStatistics = "false"
                    }
                }
            }
        }

        VerticalScrollDecorator { }
    }
}
