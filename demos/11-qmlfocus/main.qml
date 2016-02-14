import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 200
    height: 200

    GridView {
        anchors.fill: parent
        focus: true;
        model: 4
        delegate: MyText { width: 100; height: 100 }
    }

}

