import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB
import "pages"

ApplicationWindow
{
//    initialPage: Component { }
    cover: Qt.resolvedUrl("cover/CoverPage.qml")
    allowedOrientations: defaultAllowedOrientations

    Connections {
        target: translator
    }

    Connections {
        target: settings
    }


    Component.onCompleted: {
        var language = settings.settingLanguage
        if (language != "-??") {
            translator.setTranslation(language)
            pageStack.push(Qt.resolvedUrl("pages/MenuPage.qml"))
        }        
        else {
            pageStack.push(Qt.resolvedUrl("pages/SelectLanguagePage.qml"))
        }
        DB.dbInitGameStatistics("gameStatistics")
        DB.dbInitGameStatistics("gamePracticeStatistics")
        DB.dbInitGameStatistics("gameUserUserStatistics")
        DB.dbInitGameStatus()
        DB.dbInitLocationGameSave()
    }
}
