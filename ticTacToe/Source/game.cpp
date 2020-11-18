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
void Game::confirmWinner(const int &count, int *tempo){
    if(count == 3){
      qDebug()<<"Winner found "<<currentMove<<" With count ="<<count;
      winner = currentMove;
    }
    else if( count % 3 == 0 && count != 6)
    {
        int diff1 = tempo[1] - tempo[0];
        int diff2 = tempo[2] - tempo[1];
        if(diff1 == diff2 && tempo[0] != 4 && diff1 != 2) {
            winner = currentMove;
            qDebug()<<"Winner found "<<currentMove;

            qDebug()<<"Temp Array "<<tempo[0]<<" "<<tempo[1]<<" "<<tempo[2];
        }
    }
}
void Game::searchWinner(const int &len){
    int tempo[len];
    int tempoTracker = 0;
    for (int z = 0; z < len; z++){
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
    qDebug()<<"Len is"<<len;
    if(len == 4){
        int tempArrayFor4Moves[3] = {tempo[1],tempo[2],tempo[3]};
        confirmWinner(count - tempo[0], tempArrayFor4Moves);
        if(winner == "") {
           int defaultCount = count;
           for(int k = len - 1; k > 0; k-- ){
               for(int l = 0; l < 3; l++) {
                   if(k == l ||( k == 1 && l == 2)) {
                       tempArrayFor4Moves[l] = tempo[l + 1];
                   }
                   else {
                    tempArrayFor4Moves[l] = tempo[l];
                   }
               }
               count = defaultCount;
               count = count - tempo[k];
               qDebug()<<"Temp Array for 4 moves"<<tempArrayFor4Moves[0]<<" "<<tempArrayFor4Moves[1]<<" "<<tempArrayFor4Moves[2];
               qDebug()<<"Count is"<<count;
               confirmWinner(count,tempArrayFor4Moves);
               if(winner != "")
                   break;
           }
        }
         qDebug()<<"Temp Array "<<tempo[0]<<" "<<tempo[1]<<" "<<tempo[2]<<" "<<tempo[3];
    }
    else {
        confirmWinner(count,tempo);
    }
}
void Game::setMoves(){
    get2DIndex();
    gameBoard[row][column] = currentMove;
    if(progress < 5){
        if(progress <= 2){
            qDebug()<<"4 moves done";
            searchWinner(4);
        }
        else {
            qDebug()<<"3 moves done";
            searchWinner(3);
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
