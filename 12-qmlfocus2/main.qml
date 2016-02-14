import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id: root

    Rectangle {
        anchors.fill: parent
        color:"black";
        Keys.onPressed: {
            if (event.key === 81) {
                Qt.quit();
            }
        }

        Row {
            width: root.width
            Clicker {
                id: a
                focus: true; width: root.width/3; height: root.height;
                KeyNavigation.left: c
                KeyNavigation.right: b
            }
            Clicker {
                id: b
                width: root.width/3; height: root.height;
                KeyNavigation.left: a
                KeyNavigation.right: c
            }

            Clicker {
                id: c
                width: root.width/3; height: root.height;
                KeyNavigation.left: b
                KeyNavigation.right: a
            }
        }

    }
}

