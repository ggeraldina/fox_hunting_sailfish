import QtQuick 2.0

Rectangle {
    property alias littera: text.text
    width: 30
    height: 50
    color: "lightGreen"

    Text {
        id: text
        anchors.centerIn: parent
        text: "Fox"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: { console.log("hi!" + model.index)}
    }
}


