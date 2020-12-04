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
    Timer{
        id:timer
        function delay(callback){
            timer.interval = 500;
            timer.repeat = false;
            timer.triggered.connect(callback)
            timer.triggered.connect(function release(){
                timer.triggered.disconnect(callback);
                timer.triggered.disconnect(release);
            });
            timer.start();
        }
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
                if(ticTacToe.ui_winner){
                    console.log("Winner is",ticTacToe.ui_winner);
                }
                else {
                    console.log(ticTacToe.ui_player);
                    scores.children[0].children[2].text = ticTacToe.ui_player + " Turn";
                    lineTxt.text = ticTacToe.ui_player
                    if(ticTacToe.ui_player === "X"){
                        txt2 = "O";
                        scores.children[0].children[2].text = txt2 + " Turn";

                    }
                    else {
                        txt2= "X"
                        scores.children[0].children[2].text = txt2 + " Turn";
                    }
                    function endGame(){
                        gridParent.visible = false;
                        gameOver.visible = true;
                        xdiv.children[1].text = ticTacToe.ui_xScores
                        odiv.children[1].text = ticTacToe.ui_oScores
                        console.log(scores.children[0].children[2].text = ticTacToe.ui_winner + "WON!!");
                        console.log("Winner is",ticTacToe.ui_winner);
                    }

                    function callBack(){
                        ticTacToe.ui_slot = btnClicked;
                        if(ticTacToe.ui_winner){
                            if(ticTacToe.ui_winner !== ticTacToe.ui_player){
                                grid.children[ticTacToe.ui_slot].children[0].text = txt2;
                                timer.delay(endGame)
                            }
                            else {
                                endGame();
                            }
                        }
                        else {
                            grid.children[ticTacToe.ui_slot].children[0].text = txt2;
                            scores.children[0].children[2].text = ticTacToe.ui_player + " Turn";
                        }
                    }
                    timer.delay(callBack);
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
/** Next Commits
  *Winning StrikeThrough
  *delay for Computer Win
  *App FontSize/Animation
  *medium level logic
  *multiplayer
  */
