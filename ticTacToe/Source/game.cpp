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
    //Predict the Winner()
    if(progress < 5){
        int tempo[3];
        int tempoTracker = 0;
        for (int z = 0; z < 3; z++){
            tempo[z] = 0;
        }
        int count = 0, matIterator = 0;
        for(int i = 0; i < 3; i++) {
            for (int j = 0; j< 3; j++){
                if(gameBoard[i][j] == currentMove){
                    count = count + (matIterator + j);
                    tempo[tempoTracker] = (matIterator + j);
                    tempoTracker++;
                }
                if(j == 2) {
                    matIterator+=3;
                }
            }
        }
        qDebug()<<"searching for winner...Count is "<<count;

        if(count == 21 || count == 3){
          qDebug()<<"Winner found "<<currentMove<<" With count ="<<count;
          winner = currentMove;
        }
        else if( count % 3 == 0 && count != 6)
        {
            int diff1 = tempo[1] - tempo[0];
            int diff2 = tempo[2] - tempo[1];
            if(diff1 == diff2) {
                winner = currentMove;
                qDebug()<<"Winner found "<<currentMove;

                qDebug()<<"Temp Array "<<tempo[0]<<" "<<tempo[1]<<" "<<tempo[2];
            }
        }
    }
    temp = progressArray[progress];
    progressArray[progress] = index;
    progress--;
}
void Game::initialiseGame(const int i)
{
    if(winner != ""){
        return;
    }
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
        //If winner found terminate and render winner
        if(winner == ""){
            computerMove();
        }
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
QString Game::gameWinner() const{
    return winner;
}
void Game::RefreshGame(){
    for(int i = 0;i < 9; i++) {
        progressArray[i] = i;
    }
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j< 3; j++){
            gameBoard[i][j] = "";
        }
    }
    progress = 8;
    currentMove = "X";
    winner = "";
    qDebug() <<"game Mode Changed";
}
QString Game::player() const{
    return refMove;
}
