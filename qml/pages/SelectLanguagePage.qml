import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait

    Connections {
            target: translator
    }

    Connections {
            target: settings
    }

    PageHeader {
        id: headerPage
        title: qsTr("Fox hunting
Охота на лис")
    }

    Column {
        id: column
        anchors {
            top: headerPage.bottom
            right: page.right
            left: page.left
            bottom: page.bottom
        }
        spacing: Theme.paddingMedium

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Select language, please")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeLarge
        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Выберите, пожалуйста, язык")
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeLarge
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: Theme.paddingMedium

            Button {
              text: "EN"
              width: 100
              onClicked: {
                  translator.setTranslation("-en")
                  settings.settingLanguage = "-en"
                  pageStack.replace(Qt.resolvedUrl("MenuPage.qml"))
              }
            }

            Button {
              text: "RU"
              width: 100
              onClicked: {
                  translator.setTranslation("-ru")
                  settings.settingLanguage = "-ru"
                  pageStack.replace(Qt.resolvedUrl("MenuPage.qml"))
              }
            }
        }
    }
}


