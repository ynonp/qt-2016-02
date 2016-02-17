import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Mouse Demo"
    id: root

    Rectangle {
        color: "lightblue"
        anchors.fill: parent
        Text {
            id: t1
            text: m1.mouseX + "," + m1.mouseY
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            id: m1
        }
    }
}
















