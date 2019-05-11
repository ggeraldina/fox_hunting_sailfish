import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property string typeGame: "UserUser"
    property int spacingGrid: 1
    property int baseFieldSize: settings.settingBaseTableSize
    property int quantityFoxes: settings.settingNumberFoxes
    property int baseWidthHeight: page.width * (9 / baseFieldSize) / 15
    property int level: 0
    property string tableName: "gameUserUserStatistics"

    Component.onCompleted: {
        DB.dbPrintTable("locationGameSave")
        var statusGame = "game"
        DB.dbInsertRowGameStatus(typeGame, level, quantityFoxes, baseFieldSize, statusGame)
    }

}
