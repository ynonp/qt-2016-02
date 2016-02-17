import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr(MainViewMgr.appName)

    Button {
        id: b1
        text: "Click To Inc"
        onClicked: MainViewMgr.inc()
    }

    Button {
        y: b1.y + b1.height + 5
        text: "Reset"
        onClicked: MainViewMgr.count = 0
    }

    Label {
        text: "You clicked %1 times".arg(MainViewMgr.count)
        anchors.centerIn: parent
    }
}













