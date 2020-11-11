import QtQuick 2.0

Rectangle {
    id: btn
    color: "purple";
    width: parent.width/3;
    height: parent.height/3
    Text {
        id: lineTxt
        text:""
    }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        hoverEnabled: true
        onEntered: btn.state = "hover"
        onExited: btn.state = ""
        onClicked: {
            if(!lineTxt.text){
                let btnClicked, txt2;
                btn.radius = 5
                for(var i = 0; i < grid.children.length ; i++){
                    if(grid.children[i].radius === 5){
                        btnClicked = i
                        btn.radius = 0;
                        break;
                    }
                }
                if(!ticTacToe.ui_winner){
                    lineTxt.text = ticTacToe.ui_player
                    if(ticTacToe.ui_player === "X"){
                        txt2 = "O";
                    }
                    else {
                        txt2= "X"
                    }
                    ticTacToe.ui_slot = btnClicked;
                    if(ticTacToe.ui_winner !== "X"){
                        grid.children[ticTacToe.ui_slot].children[0].text = txt2;
                    }
                }
                else {
                    console.log("Winner is",ticTacToe.ui_winner);
                }
            }
        }
    }
    states: [
        State {
            name: "hover"
            PropertyChanges {
                target:btn;
            }
        }
    ]
}
