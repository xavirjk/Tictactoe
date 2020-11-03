import QtQuick 2.12
import QtQuick.Window 2.12
Item {
    Rectangle{
    id: mainView
    anchors.fill: parent
    Rectangle {
        id: header
        height: 100
        width: parent.width
        color: "purple"
        Rectangle {
            width: 200
            height: 50
            anchors.centerIn: parent
            color: "beige"
            Text {
                text : ticTacToe.ui_welcomeMessage
            }
        }
    }
    Rectangle {
        width: parent.width
        color: "white"
        anchors {
            margins: 20
            top: header.bottom
            bottom:footer.top
        }
        Item {
            function test(div,ref){
                function commonGroup(mode){
                    ref.color = "green"
                    ref.radius = 10;
                    ref.height = ref.height + 10
                    ticTacToe.ui_select = mode;
                }

                if(div === "div1" && ref.radius !== 10){
                    commonGroup("multiplayer");
                    div2.radius = 0;
                    div2.color = "beige";
                    div2.height = div2.height - 10
                }
                else if(div === "div2" && ref.radius !== 10){
                    commonGroup("simulation");
                    div1.radius = 0;
                    div1.color = "beige";
                    div1.height = div1.height - 10
                }
            }
            id: baseDiv
            anchors {
                fill: parent
                margins: 50
            }
            Rectangle {
                id: div1
                width: parent.width/2 - 20;
                height: parent.height;
                color: "beige"
                Text {
                    text: "Multiplayer"
                }
                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    hoverEnabled: true
                    onEntered: div1.state = "hover"
                    onExited: div1.state = ""
                    onClicked: {
                        baseDiv.test("div1",div1);
                    }
                }
                states: [
                    State {
                        name: "hover"
                        PropertyChanges {
                            target: div1
                        }
                    }
                ]
            }
            Rectangle {
                id: div2
                width: parent.width/2 - 20;
                height: parent.height;
                color: "beige"
                anchors.right: parent.right
                Text {
                    text: "Vs Comp"
                }
                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    hoverEnabled: true
                    onEntered: div2.state = "hover"
                    onExited: div2.state = ""
                    onClicked: {
                        baseDiv.test("div2",div2);
                    }
                }
                states: [
                    State {
                        name: "hover"
                        PropertyChanges {
                            target: div2
                        }
                    }
                ]
            }
        }
    }
    Rectangle {
        id: footer
        width: parent.width
        height: 100
        anchors {
            bottom: parent.bottom
            margins: 10
        }
        Rectangle {
            id: startButton
            width: 100
            height: 40
            color: "red"
            radius: 5
            anchors.centerIn: parent
            Text {
                id: okButton
                text: "Start"
            }
            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                hoverEnabled: true
                onEntered: startButton.state = "hover"
                onExited: startButton.state = ""
                onClicked:{
                    if(ticTacToe.ui_select === "multiplayer"){
                         console.log("selection",ticTacToe.ui_select);
                    }
                    else {
                        contentFrame.replace("qrc:/Views/D.qml");
                        console.log("Play  vs Computer")
                    }
                }
            }
            states: [
                State {
                    name: "hover"
                    PropertyChanges {
                        target: startButton
                        color: "green"

                    }
                }
            ]
        }

        color: "purple"
    }
}
}
