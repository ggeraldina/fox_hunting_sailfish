import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB
import "components/statistics_page"

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait

    ListModel {
        id: listModel
        Component.onCompleted: {
            DB.dbReadGameStatistics()
        }
    }

    ListModel {
        id: listModelPractice
        Component.onCompleted: {
            DB.dbReadGamePracticeStatistics()
        }
    }

    ListModel {
        id: listModelUserUser
        Component.onCompleted: {
            DB.dbReadGameUserUserStatistics()
        }
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
                    title: qsTr("Game's statistics")
                    anchors.right: buttonDeleteStatistics.left
                }

                IconButton {
                    id: buttonDeleteStatistics
                    anchors.right: parent.right
                    // подчеркивание icon.source красным в Qt Creator - это нормально
                    icon.source: "image://theme/icon-m-delete"
                    onClicked: {
                        DB.dbDeleteAllGameStatistics()
                    }
                }
            }

            Column {
                spacing: Theme.paddingMedium
                width: flickable.width

                ExpandingSectionGroup {
                    SectionGameAI {

                    }

                    SectionGamePractice {

                    }

                    SectionGameUserUser {

                    }
                }
            }
        }

        VerticalScrollDecorator { }
    }
}
