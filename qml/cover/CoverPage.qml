import QtQuick 2.0
import Sailfish.Silica 1.0

CoverBackground {

        Image {
            height: parent.width
            width: parent.width
            anchors.centerIn: parent
            source: "qrc:/image/coverFox.png"
        }

        Label {
            id: label
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: 10
            }

            text: qsTr("Fox hunting")
        }
}
