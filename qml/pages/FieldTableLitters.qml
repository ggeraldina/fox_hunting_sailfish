import QtQuick 2.0


Rectangle {
    width: baseWidthHeight * baseFieldSize
    height: baseWidthHeight
    color: "transparent";

    Grid {
        id: fieldLitters
        spacing: spacingGrid
        anchors.fill: parent
        columns: baseFieldSize

        ListModel {
            id: dataModelLitters

            Component.onCompleted: {
                for(var i = 0; i < baseFieldSize; i++){
                    append({ name:  String.fromCharCode(i + ("A").charCodeAt())});
                }
            }
        }


        Repeater {
            model: dataModelLitters

            delegate: LittersCell {
                height: baseWidthHeight
                width: baseWidthHeight
                litteraDigit: name
            }
        }
    }
}
