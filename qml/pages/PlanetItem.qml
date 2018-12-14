import QtQuick 2.0

Rectangle {
    property alias planetName: text.text
    property alias planetColor: planetCircle.color
    height: 120
    radius: 3
    color: "white"
    width: 200
    Text {
        id: text
        anchors.centerIn: parent
        text: "Planet name"
    }
    Rectangle {
        id: planetCircle
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 30
        width: 60
        height: 60
        radius: 30
        color: "white"
    }
}
