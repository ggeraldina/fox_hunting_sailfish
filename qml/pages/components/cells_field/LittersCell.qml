import QtQuick 2.0

Rectangle {
    property alias litteraDigit: text.text
    color: "lightBlue"
    Text {
        id: text
        anchors.centerIn: parent
        text: "Littera"
    }
}

