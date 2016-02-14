import QtQuick 2.3
import QtQuick.Window 2.2
import Shapes 1.0

Window {
    visible: true
    id: root
    Column {
        MyItem { height: root.height / 3; width: root.width }
        MyItem { height: root.height / 3; width: root.width }
        MyItem { height: root.height / 3; width: root.width }
    }


}

