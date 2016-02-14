import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    property string text: ""

    id: root
    color: focus ? "yellow" : "gray"
    width:100
    height: 100

    border {
        width: 1
        color: "black"
    }

    Text {
        anchors.centerIn: parent
        text: root.text
    }

    Keys.onPressed: {
        root.text += event.text
    }
}

