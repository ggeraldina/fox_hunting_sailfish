import QtQuick 2.0
import Sailfish.Silica 1.0
import QmlSettings 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait

    QmlSettings {
        id: settings
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
            bottomMargin: 20
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
                width: page.width
                currentIndex: settings.settingBaseTableSize - 7
                label: qsTr("Size of games field")

                menu: ContextMenu {
                    MenuItem {
                        text: "7"
                        onClicked: settings.setBaseTableSize(7)
                    }
                    MenuItem {
                        text: "8"
                        onClicked: settings.setBaseTableSize(8)
                    }
                    MenuItem {
                        text: "9"
                        onClicked: settings.setBaseTableSize(9)
                    }
                }
            }

            ComboBox {
                width: page.width
                currentIndex: settings.settingNumberFoxes - 3
                label: qsTr("Amount foxes")

                menu: ContextMenu {
                    MenuItem {
                        text: "3"
                        onClicked: settings.setNumberFoxes(3)
                    }
                    MenuItem {
                        text: "4"
                        onClicked: settings.setNumberFoxes(4)
                    }
                }
            }

            ComboBox {
                width: page.width
                currentIndex: settings.settingSpeedStepComp / 500 - 1
                label: qsTr("Speed of computer's steps")

                menu: ContextMenu {
                    MenuItem {
                        text: qsTr("0,5 sec")
                        onClicked: settings.setSpeedStepComp(500)
                    }
                    MenuItem {
                        text: qsTr("1 sec")
                        onClicked: settings.setSpeedStepComp(1000)
                    }
                }
            }

            Slider {
                width: page.width
                label: qsTr("Volume of effects")
                value: settings.settingVolumeEffects
                valueText: value.toFixed(1)
                minimumValue: 0
                maximumValue: 1
                stepSize: 0.1
                on_OldValueChanged: {
                    settings.setVolumeEffects(value);
                }
            }
        }

        VerticalScrollDecorator { }
    }
}
