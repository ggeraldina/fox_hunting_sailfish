import QtQuick 2.0
import Sailfish.Silica 1.0
import QmlSettings 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property int currentIndexBaseTableSize: settings.settingBaseTableSize - 7
    property int currentIndexNumberFoxes: settings.settingNumberFoxes - 3
    property int currentIndexSpeedStepComp: settings.settingSpeedStepComp / 500 - 1

    QmlSettings {
        id: settings
        onSettingBaseTableSizeChanged: comboBoxBaseTableSize.currentIndex = settings.settingBaseTableSize - 7
        onSettingNumberFoxesChanged: comboBoxNumberFoxes.currentIndex = settings.settingNumberFoxes - 3
        onSettingSpeedStepCompChanged: comboBoxSpeedStepComp.currentIndex = settings.settingSpeedStepComp / 500 - 1
        onSettingVolumeEffectsChanged: sliderVolumeEffects.value = settings.settingVolumeEffects
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
            bottomMargin: 20 + buttonDefaultSettings.height
        }

        Column {
            id: column
            width: flickable.width
            spacing: Theme.paddingMedium

            PageHeader {
                id: headerPage
                title: qsTr("Fox hunting")
            }

            ComboBox {
                id: comboBoxBaseTableSize
                width: page.width
                currentIndex: currentIndexBaseTableSize
                label: qsTr("Size of games field")

                menu: ContextMenu {
                    MenuItem {
                        text: "7"
                        onClicked: settings.settingBaseTableSize = 7
                    }
                    MenuItem {
                        text: "8"
                        onClicked: settings.settingBaseTableSize = 8
                    }
                    MenuItem {
                        text: "9"
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
        }

        VerticalScrollDecorator { }
    }


    Button {
        id: buttonDefaultSettings
        width: page.width
        anchors.bottom: page.bottom
        text: qsTr("Apply default settings")
        onClicked: {
            settings.updateToDefaultSettings()
        }
    }
}
