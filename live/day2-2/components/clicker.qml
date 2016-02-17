import QtQuick 2.0

Rectangle {
    property bool isActive: false
    property color activeColor: "lightblue"
    property color inactiveColor: "darkblue"
    property alias text: t1.text

    signal activated

    id: root
    color: activeColor

    transitions: [
        Transition {
            from: "active"
            to: "inactive"
            reversible: true

            PropertyAnimation {
                properties: "color, rotation"
                duration: 1000
            }


        }
    ]

    states:  [
        State {
            name: "active"
            when: isActive
            PropertyChanges {
                target: root
                color: activeColor
            }
            PropertyChanges {
                target: root
                rotation: 20
            }
        },

        State {
            name: "inactive"
            when: !isActive
            PropertyChanges {
                target: root
                color: inactiveColor
            }
        }

    ]


    Text {
        id: t1
        text: "I'm a clicker"
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.isActive = !root.isActive
            if (root.isActive) {
                activated()
            }
        }
    }
}









