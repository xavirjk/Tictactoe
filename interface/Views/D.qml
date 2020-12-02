import QtQuick 2.0
import QtQuick.Controls 2.0
import components 1.0
Item {
    function getCurrentIndex(){
        checkbox.currentIndex = ticTacToe.ui_gameMode
    }

    Component.onCompleted: getCurrentIndex();
    Rectangle{
        id: dView
        anchors.fill: parent
        Rectangle {
            id: comboDiv
            width: parent.width
            height: 40
            ComboBox {
                id: checkbox
                textRole: "text"
                valueRole: "value"
                model: [
                    {text: "Easy", value: 0},
                    {text: "Medium", value: 1},
                    {text: "Impossible", value: 2},
                ]
                onActivated:{
                    ticTacToe.ui_gameMode = currentValue
                    contentFrame.replace("qrc:/Views/D.qml")
                }

            }
        }
        Rectangle {
            id:scores
            width: parent.width
            height: 80
            anchors {
                top: comboDiv.bottom
                margins: 10
            }
            Rectangle {
                height: parent.height
                width: parent.width/2
                anchors {
                    centerIn: parent
                    margins: 10
                }
                Rectangle {
                    id:xdiv
                    height: parent.height/2
                    width: parent.width/2.5
                    color: "purple"
                    radius: 5
                    anchors {
                        verticalCenter: parent.verticalCenter
                        left: parent.left
                    }
                    Text {
                        text: "X"
                        anchors {
                            left: parent.left
                        }
                    }
                    Text {
                        text: ticTacToe.ui_xScores
                        anchors {
                            right: parent.right
                        }
                    }

                    border.color: "green"
                    border.width: 3
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            xdiv.border.color = "green"
                            xdiv.border.width = 3
                            odiv.border.color = "black"
                            odiv.border.width = 1
                            ticTacToe.ui_player = "X";
                        }
                    }

                }
                Rectangle {
                    id: odiv
                    height: parent.height/2
                    width: parent.width/2.5
                    color: "purple"
                    radius: 5
                    anchors {
                        verticalCenter: parent.verticalCenter
                        right: parent.right
                    }
                    Text {
                        text: "O"
                        anchors {
                            left: parent.left
                        }
                    }
                    Text {
                        text: ticTacToe.ui_oScores
                        anchors {
                            right: parent.right
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            odiv.border.color = "green"
                            odiv.border.width = 3
                            xdiv.border.color = "black"
                            xdiv.border.width = 1
                            ticTacToe.ui_player = "O";
                        }
                    }
                }
                Text {
                    anchors {
                        bottom: parent.bottom
                        horizontalCenter: parent.horizontalCenter
                    }

                    text: "Welcome"
                }
            }
        }
        Rectangle {
            id: middleRect
            width: parent.width
            color: "purple"
            anchors {
                top: scores.bottom
                bottom: refresh.top
            }
            Rectangle {
                id: gameOver
                visible: false
                anchors.fill: parent
                color: parent.color
                anchors.centerIn: parent
                Text {
                    text: "Game Over"
                    anchors.centerIn: parent
                }
            }

            Rectangle {
                id: gridParent
                color: "green"
                width: 0.3*parent.width
                height: 3/4*parent.height
                anchors {
                    centerIn: parent
                }
                Grid {
                    id: grid
                    columns: 3
                    spacing: 6
                    width: parent.width
                    height: parent.height
                    GameButton {}
                    GameButton {radius: 2}
                    GameButton {}
                    GameButton {}
                    GameButton {}
                    GameButton {}
                    GameButton {}
                    GameButton {}
                    GameButton {}
                      }
            }
        }
        Rectangle {
            id: refresh
            width: parent.width
            height: 80
            anchors {
                bottom: parent.bottom
            }
            Text{
                text: "Refresh"
                anchors.centerIn: parent
            }

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                hoverEnabled: true
                onEntered: refresh.state = "hover"
                onExited: refresh.state = ""
                onClicked: {
                    ticTacToe.ui_gameMode = checkbox.currentIndex
                    for(let i = 0; i < grid.children.length; i++){
                        grid.children[i].children[0].text = "";
                    }
                    scores.children[0].children[2].text = "Welcome";
                    gridParent.visible = true;

                }
            }
            states: [
                State {
                    name: "hover"
                    PropertyChanges {
                        target: refresh
                        color: Qt.darker("green")
                        radius: 5

                    }
                }
            ]
        }
    }
}
