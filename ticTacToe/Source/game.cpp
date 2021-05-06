#include "game.h"
#include <ctime>
#include <cstdlib>
#include <QDebug>
#include <iostream>
using namespace std;
Game::Game(QObject *parent)
    :QObject(parent){
    for(int i = 0; i < 9; i++){
        progressArray[i] = i;
    }
    controller = new ModeController(this);
    heapsort = new HeapSort(this);
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

void Game::searchWinner(){
    int workinProgArray[3];
    for (int z = 0; z < 3; z++){
        workinProgArray[z] = 0;
    }
    int row_iterate = 0;
    int col_iterate = 0;
    int diag_iterate = 0;
    qDebug()<<"checking new Row";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(gameBoard[i][j] != currentMove)
                break;
            else
                workinProgArray[j] = row_iterate + j;
            if(j == 2){
                winner = currentMove;
                qDebug()<<"winner found "<<currentMove;
                qDebug()<<"working progress Arr "<<workinProgArray[0]<<" "<<workinProgArray[1]<< " "<<workinProgArray[2];
            }
        }
        if(winner != "")
            break;
        row_iterate+=3;
    }
    if(winner == ""){
        qDebug()<<"checking new Col";
        int trackCol = 0;
        col_iterate = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(gameBoard[j][i] != currentMove){
                    col_iterate = trackCol;
                     break;
                }
                else {
                    workinProgArray[j] = col_iterate;
                }
                if(j == 2){
                    winner = currentMove;
                    qDebug()<<"winner found "<<currentMove;
                    qDebug()<<"working progress Arr "<<workinProgArray[0]<<" "<<workinProgArray[1]<< " "<<workinProgArray[2];
                }
                col_iterate = col_iterate + 3;
            }
            col_iterate+=1;
            trackCol+=1;
            if(winner != "")
                break;
        }
    }
    if(winner == ""){
        qDebug()<<"checking new Diag l to R";
        for(int i = 0; i < 3; i++){
            if(gameBoard[i][i] == currentMove){
                workinProgArray[i] = diag_iterate;
            }
            else
                break;
            if(i == 2){
                winner = currentMove;
                qDebug()<<"winner found "<<currentMove;
                qDebug()<<"working progress Arr "<<workinProgArray[0]<<" "<<workinProgArray[1]<< " "<<workinProgArray[2];
            }
            diag_iterate += 4;
        }
    }
    if(winner == ""){
         qDebug()<<"checking new Diag R to l";
        int j = 2;
        diag_iterate = 2;
        for(int i = 0; i < 3; i++){
            if(gameBoard[i][j] == currentMove){
                workinProgArray[i] = diag_iterate;
                j -= 1;
            }
            else {
                break;
            }
            if(i == 2){
                winner = currentMove;
                qDebug()<<"winner found "<<currentMove;
                qDebug()<<"working progress Arr "<<workinProgArray[0]<<" "<<workinProgArray[1]<< " "<<workinProgArray[2];
            }
            diag_iterate += 2;
        }
    }
    if(winner == "X")
        xWins++;
    else if (winner == "O")
        oWins++;
    if(winner !=""){
        for (int i = 0; i < 3; i++){
            winMoves.insert(i,workinProgArray[i]);
            winningMoves[i] = workinProgArray[i];
        }
     qDebug()<<"XWinns "<<xWins<<" OWinns "<<oWins<<" "<<winMoves.at(2)<<" Size: "<<winMoves.size();
    }
}
void Game::setMoves(){
    get2DIndex();
    gameBoard[row][column] = currentMove;
    temp = progressArray[progress];
    qDebug()<<"Progress "<<progress;
    progressArray[progress] = index;
    if(progress < 5){
       searchWinner();
    }
    progress--;
}
void Game::initialiseGame(const int i,QString playSelect){
    if(winner != ""){
        return;
    }
    currentMove = refMove;
    index = i;
    qDebug()<<" Human Move Start"<<currentMove;
    counterProgress();
    if(progress > -1){
        qDebug()<<"Human Move End "<<currentMove;
        if(winner == ""){
            if(playSelect == "simulation" || playSelect == ""){
                 computerMove();
            }
            else {
                if(currentMove == "X"){
                    refMove = "O";
                }
                else {
                    refMove = "X";
                }
            }
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
    if(mode == 0){
        int random = getRandom();
        index = progressArray[random];
        if(progress < 5) {
            int tempIndex = index;
            index = controller ->mode2Slot(progressArray,progress,"mode1");
            if(index == -1)
                index = tempIndex;
        }
        setMoves();
        progressArray[random] = temp;
    }
    else if( mode == 1){
        if(progress > 5){
            int random = getRandom();
            index = progressArray[random];
            setMoves();
            progressArray[random] = temp;
        }
        else {
            index = controller->mode2Slot(progressArray,progress, "mode2");
            counterProgress();
        }
    }
    else if (mode == 2) {
        //in progress
        int indexSelect = progressArray[8];
        if(progress == 7){
            if(indexSelect == 4){
                int arr[] = {0,2,6,8};
                index = selectRandomFromIndexes(arr);
            }
            else if(indexSelect % 2 == 0)
                index = 4;
            else{
                if(indexSelect == 1)
                    index = 0;
                else if(indexSelect == 3)
                    index = 0;
                else if(indexSelect == 5)
                    index = 2;
                else if (indexSelect == 7)
                    index = 6;
            }
            counterProgress();
        }
        else {
            index = controller->mode2Slot(progressArray,progress, "mode3");
            counterProgress();
        }
    }
    qDebug()<<"Computer Move End "<<currentMove;
}
void Game::counterProgress(){
    int ref = 0;
    for(int j = 0; j < 9; j++){
        if(progressArray[j] == index){
            ref = j;
            break;
        }
    }
    setMoves();
    progressArray[ref] = temp;
}
void Game::setPlayer(const QString &player){
    if(progress == 8){
        currentMove = player;
        refMove = currentMove;
    }
}
int Game::selectRandomFromIndexes(const int *list){
    srand(time(0));
    return list[rand()%5];
}
int Game::getRandom(){
    srand(time(0));
    return rand()%(progress + 1);
}
int Game::accessComputerMove(){
    return index;
}
int Game::gameMode(){
    return mode;
}
QString Game::gameWinner() const{
    return winner;
}
void Game::RefreshGame(int gameMode){
    for(int i = 0;i < 9; i++) {
        progressArray[i] = i;
    }
    for(int i = 0; i < 3; i++) {
        if(!winMoves.isEmpty()){
            winMoves.pop_front();
        }
        for (int j = 0; j< 3; j++){
            gameBoard[i][j] = "";
        }
    }
    progress = 8;
    currentMove = "X";
    qDebug()<<"exec sorm"<<SorM;
    if(SorM == "multiplayer"){
        qDebug()<<"exec";
        refMove = currentMove;
    }
    winner = "";
    mode = gameMode;
    qDebug() <<"game Mode Changed"<<mode <<" "<<currentMove << refMove;
}
QString Game::player() const{
    return refMove;
}
void Game::selectedMode(const QString val){
    SorM = val;
}
int Game::getScores(const QString &player){
    if(player == "X"){
        return xWins;
    }
    else
        return oWins;
}
int *Game::accessProgressArray(){
    return progressArray;
}
int Game::inProgress(){
    return progress;
}
QJsonArray Game::getWinningMoves(){
    return winMoves;
}
