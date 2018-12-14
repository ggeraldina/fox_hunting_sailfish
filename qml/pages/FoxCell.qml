import QtQuick 2.0

MouseArea {
    id: cell
    property alias littera: text.text
    width: 30
    height: 50

    Rectangle {
        width: parent.width
        height: parent.height
        color: "lightGreen"
        Text {
            id: text
            anchors.centerIn: parent
            text: "Fox"
        }
    }

    onClicked: { console.log("hi!")}

}


