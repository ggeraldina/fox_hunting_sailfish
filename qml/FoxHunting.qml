import QtQuick 2.0
import Sailfish.Silica 1.0
import QmlTranslator 1.0
import QmlSettings 1.0
import "pages"

ApplicationWindow
{
    initialPage: Component { SelectLanguagePage { } }
    cover: Qt.resolvedUrl("cover/CoverPage.qml")
    allowedOrientations: defaultAllowedOrientations

    QmlTranslator {
        id: qmlTranslator
    }

    QmlSettings {
        id: settings
    }

    Component.onCompleted: {
        var language = settings.settingLanguage
        if (language != "-??") {
            qmlTranslator.setTranslation(language)
            pageStack.push(Qt.resolvedUrl("pages/MenuPage.qml"))
        }
    }

}
