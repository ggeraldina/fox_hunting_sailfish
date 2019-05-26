import QtQuick 2.0
import Sailfish.Silica 1.0
import "components/cells_field"
import QtQuick.LocalStorage 2.0
import "qrc:/js/database/Database.js" as DB
import TablesLocationFoxes 1.0

Dialog {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait
    property int spacingGrid: 1
    property int baseFieldSize: settings.settingBaseTableSize
    property int quantityFoxes: settings.settingNumberFoxes
    property int baseWidthHeight: page.width * (9 / baseFieldSize) / 15
    // customizable properties
    property string typeGame: ""
    property int level: 0
    property string field: ""
    property string fieldOpponent: ""
    property string nextPage: ""
    property string namePlayer1: ""
    property string namePlayer2: ""

    Connections {
        target: settings
    }

    DialogHeader {
        id: headerPage
        acceptText: qsTr("Ok")
        cancelText: qsTr("Cancel")
    }

    TablesLocationFoxes {
        id: dataModelLocation
        onAddFoxLocation: {
            var fox = 1
            var shot = 0
            DB.dbInsertRowLocationGameSave(level, quantityFoxes, baseFieldSize, field, index, fox, shot)
        }
        onRemoveFoxLocation: {
            DB.dbDeleteRowLocationGameSave(level, quantityFoxes, baseFieldSize, field, index)
        }
        onRemoveAllFox: {
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, field)
        }
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
            text: namePlayer1 + "! " + qsTr("Are you pleased the location of the foxes on the field?")
            width:column.width - Theme.paddingLarge * 2
            horizontalAlignment: Text.AlignJustify
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WordWrap
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeMedium
        }

        Label {
            text: qsTr("You can set the location of the foxes.")
            width:column.width - Theme.paddingLarge * 2
            horizontalAlignment: Text.AlignJustify
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WordWrap
            color: Theme.highlightColor
            font.pixelSize: Theme.fontSizeMedium
        }

        Grid {
            spacing: spacingGrid
            x: page.width / 2 - width / 2 - spacingGrid * baseFieldSize / 2
            height: spacingGrid * baseFieldSize + baseWidthHeight * (baseFieldSize + 1)
            columns: 2

            Rectangle {
                  width: baseWidthHeight
                  height: baseWidthHeight
                  color: {
                      switch (field) {
                      case "Comp":
                          color = "darkblue"
                          break
                      case "User0":
                          color = "darkblue"
                          break
                      case "User1":
                          color = "darkred"
                          break
                      }
                  }
            }

            FieldTableLitters {

            }

            FieldTableDigits{

            }

            Item {
                  width: baseWidthHeight * baseFieldSize
                  height: baseWidthHeight * baseFieldSize

                  Grid {
                      spacing: spacingGrid
                      anchors.fill: parent
                      columns: baseFieldSize
                      rows: baseFieldSize

                      Repeater {
                          id: repeaterLocation
                          delegate: Item {
                              width: baseWidthHeight
                              height: baseWidthHeight

                              Image {
                                  anchors.fill: parent
                                  source: model.backgroundURL
                              }

                              Text {
                                  anchors.centerIn: parent
                                  text:  model.text
                              }

                              MouseArea {
                                  anchors.fill: parent
                                  onClicked: {
                                      labelMessage.text = dataModelLocation.putOrRemoveFox(model.index)
                                      if (dataModelLocation.equalNumberAndCountFoxes()) {
                                          page.canAccept = true
                                      } else {
                                          page.canAccept = false
                                      }
                                  }
                              }
                          }
                      }
                  }
             }
        }

        Label {
            id: labelMessage
            text: ""
            width: column.width - Theme.paddingLarge * 2
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WordWrap
            color: Theme.secondaryColor
            font.pixelSize: Theme.fontSizeTiny
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: qsTr("Randomly")
                onClicked: {
                    dataModelLocation.generateRandomLocationFoxes()
                    labelMessage.text = ""
                    page.canAccept = true
                }
            }

            IconButton {
                id: buttonDeleteStatistics
                // подчеркивание icon.source красным в Qt Creator - это нормально
                icon.source: "image://theme/icon-m-delete"
                onClicked: {
                    dataModelLocation.cleanLocationFoxes()
                    labelMessage.text =  qsTr("Foxes less than need");
                    page.canAccept = false
                }
            }
        }
    }

    onAccepted: {
        switch (nextPage) {
        case "LocationFoxesPage.qml":
            pageStack.replace(Qt.resolvedUrl("LocationFoxesPage.qml"),
                                             { typeGame: typeGame,
                                               level: level,
                                               field: "User0",
                                               fieldOpponent: "",
                                               nextPage: "GameUserUserPage.qml",
                                               namePlayer1: namePlayer2 })
            break
        default:
            pageStack.replace(Qt.resolvedUrl(nextPage))
        }
    }

    onRejected: {
        if (settings.settingSavingGames == "false") {
            DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, field)
        }
    }

    Component.onCompleted: {
        var statusGame = "location" + field
        DB.dbInsertRowGameStatus(typeGame, level, quantityFoxes, baseFieldSize, statusGame)
        DB.dbDeleteFieldLocationGameSave(level, quantityFoxes, baseFieldSize, fieldOpponent)
        dataModelLocation.baseTableSize = baseFieldSize
        dataModelLocation.numberFoxes = quantityFoxes
        dataModelLocation.createData()
        restoreCompFoxesGame()
        repeaterLocation.model = dataModelLocation.dataFoxes
    }

    function restoreCompFoxesGame() {
        if(DB.dbExistsFieldLocationGameSave(level, quantityFoxes, baseFieldSize, field)) {
            var numberCellFoxes = DB.dbGetFoxesFieldLocationGameSave(level, quantityFoxes, baseFieldSize, field)
            for (var i = 0; i < numberCellFoxes.length; i++) {
                dataModelLocation.putOrRemoveFox(numberCellFoxes[i])
            }
            if(dataModelLocation.equalNumberAndCountFoxes()) {
                page.canAccept = true
            } else {
                page.canAccept = false
                labelMessage.text =  qsTr("Foxes less than need");
            }
        } else {
            dataModelLocation.generateRandomLocationFoxes()
            page.canAccept = true
        }
    }
}
