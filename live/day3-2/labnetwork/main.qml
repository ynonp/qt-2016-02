import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id: root

    ColumnLayout {
        width: parent.width
        Rectangle {
            id: r1
            color: "blue"
            Layout.fillWidth: true
            Layout.preferredHeight: root.height / 4

            Row {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.margins: {
                    left: 20
                }

                TextField {
                    id: keyword
                    width: r1.width - btn.width - 50
                }

                Button {
                    id: btn
                    text: "Search"
                    onClicked: {
                        omdb.search(keyword.text)
                    }
                }
            }
        }

        Rectangle {
            color: "gold"
            Layout.fillWidth: true
            Layout.preferredHeight: root.height / 4

            Row {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.margins: {
                    left: 20
                }

                Label {
                    text: "Title: "
                }

                Label {
                    text: omdb.title
                }
            }

        }


        Rectangle {
            color: "green"
            Layout.fillWidth: true
            Layout.preferredHeight: root.height / 4
            //height: 20

            Row {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.margins: {
                    left: 20
                }

                Label {
                    text: "Year: "
                }

                Label {
                    text: omdb.year
                }
            }

        }


        Rectangle {
            color: "red"
            Layout.fillWidth: true
            Layout.preferredHeight: root.height / 4
            id: r3

            Row {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.margins: {
                    left: 20
                }

                Label {
                    text: "Image: "
                }

                Image {
                    source: omdb.imageUrl
                    fillMode: Image.PreserveAspectFit
                    height: r3.height
                }
            }
        }


    }



}

