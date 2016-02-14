import QtQuick 2.0

Rectangle {
    property bool isOn: false
    signal valueChanged(bool val)

    width: 100
    height: 200
    id: root

    states: [
        State {
            name: "off"
            when: !root.isOn
            PropertyChanges {
                target: bottom
                color: "gray"
            }
        },

        State {
            name: "on"
            when: root.isOn
            PropertyChanges {
                target: knob
                x: knob.width
            }
            PropertyChanges {
                target: bottom
                color: "yellow"
            }
        }
    ]

    transitions: [
        Transition {
            from: "off"
            to: "on"
            // reversible: true
            PropertyAnimation {
                target: knob
                properties: "x"
                duration: 100
            }
            PropertyAnimation {
                target: bottom
                properties: "color"
                duration: 100
            }
        },
        Transition {
            from: "on"
            to: "off"
            PropertyAnimation {
                target: knob
                properties: "x"
                duration: 100
            }

            ColorAnimation {
                from: "yellow"
                to: "gray"
                duration: 100
            }

        }
    ]


    Column {
        Rectangle {
            id: top
            border.color: "gray"
            border.width: 1

            width: root.width
            height: 60
            color: "white"

            Rectangle {
                id: knob
                width: parent.width / 2
                height: parent.height
                color: "black"
                x: 0
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    root.isOn = !root.isOn
                    root.valueChanged(root.isOn)
                }
            }
        }

        Rectangle {
            id: bottom
            width: root.width
            height: root.height - top.height

        }
    }
}
