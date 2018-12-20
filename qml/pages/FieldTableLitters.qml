import QtQuick 2.0


Rectangle {
    width: baseWidthHeight * 9 // - spacingGrid * 9
    height: baseWidthHeight
    color: "transparent";

    Grid {
        id: fieldLitters
        spacing: spacingGrid
        anchors.fill: parent
        columns: 9
        Repeater {
            model: ListModel {
                ListElement { name: "A"}
                ListElement { name: "B" }
                ListElement { name: "C" }
                ListElement { name: "D" }
                ListElement { name: "E" }
                ListElement { name: "F" }
                ListElement { name: "G" }
                ListElement { name: "I" }
                ListElement { name: "H" }
            }
            LittersCell {
                height: baseWidthHeight
                width: fieldLitters.width / fieldLitters.columns
                littera: name
            }
        }
    }
}
