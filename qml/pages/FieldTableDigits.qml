import QtQuick 2.0

Rectangle {
    width: baseWidthHeight
    height: baseWidthHeight * 9 // - spacingGrid * 9
    color: "transparent";

    Grid {
        id: fieldDigits
        spacing: spacingGrid
        anchors.fill: parent
        rows: 9
        Repeater {
            model: ListModel {
                ListElement { name: "1"}
                ListElement { name: "2" }
                ListElement { name: "3" }
                ListElement { name: "4" }
                ListElement { name: "5" }
                ListElement { name: "6" }
                ListElement { name: "7" }
                ListElement { name: "8" }
                ListElement { name: "9" }
            }
            LittersCell {
                height: fieldDigits.height / fieldDigits.rows
                width: baseWidthHeight
                littera: name
            }
        }
    }
}
