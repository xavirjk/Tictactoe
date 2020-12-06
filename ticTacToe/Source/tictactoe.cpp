#include "tictactoe.h"
#include <QDebug>
namespace Lib {
namespace ticTacToe {
TicTacToe::TicTacToe(QObject *parent)
    :QObject(parent)
{
    game = new Game(this);
    welcomeMessage = "TicTacToe Game";
}
TicTacToe::~TicTacToe(){}

void TicTacToe::setSelected(const QString &select){
    selected = select;

}

QString TicTacToe::getSelected() const{
    return selected;
}
void TicTacToe::setMode(const int &mode){
    gameMode = mode;
    game -> RefreshGame();
}
int TicTacToe::getMode() const{
    return  gameMode;
}
void TicTacToe::setDefaultPlayer(const QString &player){
    game ->setPlayer(player);
    Player = player;
}
QString TicTacToe::getDefaultPlayer() const{
    return game -> player();
}

void TicTacToe::interfaceGame(const int &slot){
    game ->initialiseGame(slot);
}
int TicTacToe::getSlot(){
    return game ->accessComputerMove();
}
QString TicTacToe::getWinner(){
    return game ->gameWinner();
}
int TicTacToe::getXScores(){
    return game->getScores("X");
}
int TicTacToe::getOScores(){
    return game->getScores("O");
}
QJsonArray TicTacToe::getWinningMoves(){
    return game -> getWinningMoves();
}
}}

