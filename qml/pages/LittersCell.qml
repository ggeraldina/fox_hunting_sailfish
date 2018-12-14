import QtQuick 2.0

Rectangle {
    property alias littera: text.text
    width: 30
    height: 50
    color: "lightBlue"
    Text {
        id: text
        anchors.centerIn: parent
        text: "Littera"
    }
}

