import QtQuick 2.0

Rectangle {
    id: btn
    color: "purple";
    width: parent.width/3;
    height: parent.height/3
    Text {
        id: lineTxt
        anchors.centerIn: parent
        font {
            pixelSize: 20
        }
        color: Qt.darker("black");
        text:""
    }
    Timer{
        id:timer
        function delay(callback, span){
            timer.interval = span;
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
                function commonCall(){
                    strikeThrough();
                    timer.delay(endGame,1000);
                }

                function endGame(){
                    gridParent.visible = false;
                    gameOver.visible = true;
                    xdiv.children[1].text = ticTacToe.ui_xScores
                    odiv.children[1].text = ticTacToe.ui_oScores
                    console.log(scores.children[0].children[2].text = ticTacToe.ui_winner + " - WON!!");
                    console.log("Winner is",ticTacToe.ui_winner);
                }
                function strikeThrough(){
                    for(let i = 0; i < ticTacToe.ui_winningMoves.length; i++){
                        grid.children[ticTacToe.ui_winningMoves[i]].children[0].color = "#006400"
                        grid.children[ticTacToe.ui_winningMoves[i]].children[0].font.pixelSize = 30
                        grid.children[ticTacToe.ui_winningMoves[i]].children[0].font.bold = true
                    }
                }
                function callBack(){
                    ticTacToe.ui_slot = btnClicked;
                    if(ticTacToe.ui_winner){
                        if(ticTacToe.ui_winner !== ticTacToe.ui_player){
                            grid.children[ticTacToe.ui_slot].children[0].text = txt2;
                            commonCall();
                        }
                        else {
                            commonCall();
                        }
                    }
                    else {
                        if(btnClicked !== ticTacToe.ui_slot){
                            grid.children[ticTacToe.ui_slot].children[0].text = txt2;
                            scores.children[0].children[2].text = ticTacToe.ui_player + " Turn";
                        }
                        else if(ticTacToe.ui_select !== "multiplayer") {
                            scores.children[0].children[2].text = "X-O"
                        }
                        else if(ticTacToe.ui_select === "multiplayer" && ticTacToe.ui_gameInProgress == -1) {
                            scores.children[0].children[2].text = "X-O"
                        }
                    }
                }
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
                    console.log('player',ticTacToe.ui_player);

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
                    timer.delay(callBack, 500);
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
