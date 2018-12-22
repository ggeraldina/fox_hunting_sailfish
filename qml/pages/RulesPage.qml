import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    anchors.fill: parent
    allowedOrientations: Orientation.Portrait

    SilicaFlickable {
        id: flickable
        contentWidth: column.width
        contentHeight: column.height
        anchors {
            top: page.top
            right: page.right
            left: page.left
            bottom: page.bottom
            bottomMargin: 20
        }

        Column {
            id: column
            width: flickable.width
            spacing: Theme.paddingMedium

            PageHeader {
                id: headerPage
                title: qsTr("Fox hunting")
            }

            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Rules")
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeLarge
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                color: Theme.highlightColor
                font.pixelSize: Theme.fontSizeMedium
                text: qsTr("Rules of the game 'Fox Hunting':

Order of play:
On the fields of the player and
computer (field sizes: 9x9) randomly
at four foxes hidden on each field.
The player and the computer take
turns making their shots each on
his field, trying to find all the
foxes before the opponent.
The player shoots first.
The winner is the one who
first finds all the foxes.

Feature of the game:
1) After each well-aimed
shot on a cell the fox displayed,
and shot can be repeated.
2) In case of a miss, a number is
displayed, which shows the number
of foxes hidden in all cells,
located on the same vertical,
horizontal and on both diagonals
(both undiscovered and found foxes
are taken into account). The next
move is given to the opponent.
3) Foxes can not be located
in the same cell.
4) Foxes can't be located in
neighboring cells.
")
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "New game"
                onClicked: pageStack.replace(Qt.resolvedUrl("GamePage.qml"))
            }
        }
        VerticalScrollDecorator { }
    }
}
