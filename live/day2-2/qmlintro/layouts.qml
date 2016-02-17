import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    id: root
    title: qsTr("Hello World")

    Text {
        id: t1
        text: "Hello World Hello World Hello World Hello World"
        anchors.centerIn: parent
    }

    Rectangle {
        height: 200
        color: "greenyellow"
        anchors {
            left: t1.left
            right: t1.right
            margins: {
                left: 50
                right: 50
            }

        }

    }
}








