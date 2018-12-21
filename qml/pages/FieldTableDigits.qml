import QtQuick 2.0

Rectangle {
    width: baseWidthHeight
    height: baseWidthHeight * baseFieldSize
    color: "transparent";

    Grid {
        id: fieldDigits
        spacing: spacingGrid
        anchors.fill: parent
        rows: baseFieldSize

        ListModel {
            id: dataModelDigits

            Component.onCompleted: {
                for(var i = 0; i < baseFieldSize; i++){
                    append({ name:  (i + 1).toString()});
                }
            }
        }


        Repeater {
            model: dataModelDigits

            delegate: LittersCell {
                height: baseWidthHeight
                width: baseWidthHeight
                litteraDigit: name
            }
        }
    }
}
