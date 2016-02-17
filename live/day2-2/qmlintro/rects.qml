import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    id: root
    title: qsTr("Hello World")


    Rectangle {
        id: r1
        width: root.width / 3
        height: root.height
        color: "red"
    }

    Rectangle {
        id: r2
        anchors.left: r1.right
        width: root.width / 3
        height: root.height
        anchors.margins: {
            left: 10
        }

        color: "gold"
    }

    Rectangle {
        id: r3
        anchors.left: r2.right
        width: root.width / 3
        height: root.height
        anchors.margins: {
            left: 10
        }

        color: "green"
    }

}








