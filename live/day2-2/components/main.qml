import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id: root

    Column {
        Row {
            Clicker {
                width: root.width/2; height: 100
                activeColor: "yellow"
                text: "Yo"
                onActivated: friend.text = ";)"
            }
            Clicker {
                id: friend
                width: root.width/2;
                height: 100
            }

        }

        Row {
            Clicker {
                width: root.width/2; height: 100
            }
            Clicker { width: root.width/2; height: 100 }

        }

    }



}

