import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

//    ListView {
//        model: game
//        width: 180; height: 200
//        delegate: Text {
//            text: value
//            Component.onCompleted: {
//                print("compl: " + index)
//            }
//        }
//    }


    Column {
        anchors.fill: parent

        Text {
            text: "The winner is: %1".arg(game.winner)
        }

        Grid {
            columns: 3
            width:parent.width
            height:parent.height
            Repeater {
                model: game
                Rectangle {
                    border { width: 1; color: "gray" }
                    width: parent.width / 3
                    height: parent.height / 3
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            game.play(index)
                        }
                    }

                    Text {
                        text: value
                        anchors.centerIn: parent
                    }
                }
            }

        }


    }

     Connections {
        target: game
        onDataChanged: {
            print("Data Changed: " + topLeft)
        }
    }


}

