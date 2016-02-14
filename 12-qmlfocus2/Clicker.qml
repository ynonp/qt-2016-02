import QtQuick 2.0

Item {
    id: root
    property int clicks: 0
    property int contentWidth: root.width - 2
    Keys.onReturnPressed: clicks++

    Column {
        id: col
        Rectangle {
            id: text
            height: 40
            width: contentWidth

            Text {
                anchors.fill: parent
                anchors.margins: {
                    top: 8
                    bottom: 8
                }

                text: "You clicked %1 times".arg(clicks)
                height: 40
                width: root.width
                //font.pointSize: 18;
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.Fit; minimumPixelSize: 10;
                font.pixelSize: 48
            }
        }


        Rectangle {
            id: btn
            width: contentWidth
            height: root.height - text.height
            color: root.focus ? "blue" : "lightblue"

            MouseArea {
                anchors.fill: parent
                onClicked: clicks++
            }
        }

    }



}

