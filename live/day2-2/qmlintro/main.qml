import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    id: root
    title: qsTr("Hello World")
    property int clicks: 0

    Image {
        source: "https://upload.wikimedia.org/wikipedia/en/thumb/a/a9/DuckDuckGo_Logo.svg/500px-DuckDuckGo_Logo.svg.png"
        x: root.width - root.width / 4
        width: root.width / 4
        fillMode: Image.PreserveAspectFit
        rotation: 30
    }

    Text {
        x: 50
        y: 50
        id: t1
        text: "You clicked %1 times".arg(clicks)
    }

    Button  {
        x: t1.x
        y: t1.y + t1.height + 20
        text: "Click Me"
        onClicked: clicks++
    }
}








