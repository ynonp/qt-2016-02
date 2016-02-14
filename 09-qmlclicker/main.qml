import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4

Window {
    visible: true
    id: root
    width: 400
    height: 400


    Row {
        OnOffSwitch {
            id: s1
            property int count: 0
            onValueChanged: {
                count++
            }
        }

        Text {
            text: s1.count
        }

    }


/*
    Column {
        Clicker { clicks: 5; height: root.height / 3 ; width: root.width }
        Clicker { height: root.height / 3 ; width: root.width }
        Clicker { height: root.height / 3 ; width: root.width }
    }
    */


}

