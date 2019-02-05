import QtQuick 2.0
import Sailfish.Silica 1.0
import QmlTranslator 1.0
import QmlSettings 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait

    QmlTranslator {
        id: qmlTranslator
        onLanguageChanged: {
//                  pageStack.replace(Qt.resolvedUrl("SelectLanguagePage.qml"), { }, PageStackAction.Immediate)
            pageStack.push(Qt.resolvedUrl("MenuPage.qml"))
        }
    }

    QmlSettings {
        id: settings
    }

    PageHeader {
        id: headerPage
        title: qsTr("Fox hunting")
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
                  qmlTranslator.setTranslation("-en")
                  settings.settingLanguage = "-en"
              }
            }

            Button {
              text: "RU"
              width: 100
              onClicked: {
                  qmlTranslator.setTranslation("-ru")
                  settings.settingLanguage = "-ru"
              }
            }
        }
    }
}


