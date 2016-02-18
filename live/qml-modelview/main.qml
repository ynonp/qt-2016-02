import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id: root

    property string selectedValue: ""

    Column {
        spacing: 10
        Rectangle {
            color: "lightblue"
            height: 80
            width: root.width

            Text {
                anchors.fill: parent
                text: "Selected Item = %1".arg(selectedValue);
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

        }


        GridView {
            height: root.height
            width: root.width
            model: numbersModel
            focus: true
            delegate: Text {
                color: focus ? "red" : "black";
                text: value;
                Keys.onReturnPressed: {
                    print("Index Selected: " + index);
                    print("Item Selected: " + value);
                    selectedValue = secret
                }
            }
        }
    }



}

