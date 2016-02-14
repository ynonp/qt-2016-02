import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    property int clicks: 0
    id: root

    Rectangle {
        color: "yellow"
        anchors.fill: root
        Column {
            Text {
                text: "You clicked: %1 times".arg(clicks)
            }

            Button {
                text: "Click Me"
                onClicked: clicks++
            }

        }
    }
}

