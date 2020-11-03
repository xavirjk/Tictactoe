#include "game.h"
#include <ctime>
#include <cstdlib>
#include <QDebug>
Game::Game(QObject *parent)
    :QObject(parent){
    for(int i = 0; i < 9; i++){
        progressArray[i] = i;
    }
}
Game::~Game(){}

void Game::get2DIndex(){
    row = index - 3;
    if(row >= 0) {
          column = row;
    }
    if(row < 0) {
        column = row + 3;
        row = 0;
    }
    else if(row >= 0 && row <= 2){
        row = 1;
    }
    else {
        row = 2;
        column = column - 3;
    }
}
void Game::setMoves(){
    get2DIndex();
    gameBoard[row][column] = currentMove;
    //qDebug()<<row<<" "<<column;
    //qDebug()<< gameBoard[row][column];
    //qDebug()<<progress;
    temp = progressArray[progress];
    progressArray[progress] = index;
    progress--;
}
void Game::initialiseGame(const int i)
{
    int ref = 0;
    currentMove = refMove;
    index = i;
    qDebug()<<" Human Move Start"<<currentMove;
    for(int j = 0; j < 9; j++){
        if(progressArray[j] == i){
            ref = j;
            break;
        }
    }
    if(progress > -1) {
        setMoves();
    }
    progressArray[ref] = temp;
    if(progress > -1){
        qDebug()<<"Human Move End "<<currentMove;
        computerMove();
    }
}
void Game::computerMove(){
    if(refMove == "X"){
        currentMove = "O";
    }
    else {
        currentMove = "X";
    }
    qDebug()<<"Computer Move Start "<<currentMove;
    int random = getRandom();
    index = progressArray[random];
    setMoves();
    progressArray[random] = temp;
    qDebug()<<"Computer Move End "<<currentMove;
}
void Game::setPlayer(const QString &player){
    if(progress == 8){
        currentMove = player;
        refMove = currentMove;
    }
}
int Game::getRandom(){
    srand(time(0));
    return rand()%(progress + 1);
}
int Game::accessComputerMove(){
    return index;
}
void Game::RefreshGame(){
    for(int i = 0;i < 9; i++) {
        progressArray[i] = i;
    }
    progress = 8;
    currentMove = "X";
    qDebug() <<"game Mode Changed";
}
QString Game::player() const{
    return refMove;
}
