#ifndef GAME_H
#define GAME_H

#include "ticTacToe_global.h"
#include <QObject>

class TICTACTOE_EXPORT Game: public QObject
{
public:
    Game(QObject *parent = nullptr);
    ~Game();
    void initialiseGame(const int index);
    void computerMove();
    void get2DIndex();
    void setPlayer(const QString &player);
    QString player() const;
    void setMoves();
    void RefreshGame();
    int getRandom();
    int accessComputerMove();

private:
    static const int rows = 3;
    static const int columns = 3;
    int row, column, index;
    QString currentMove = "X";
    QString refMove = currentMove;
    QString gameBoard[rows][columns];
    int progressArray[9];
    int progress = 8;
    int temp;

};

#endif // GAME_H