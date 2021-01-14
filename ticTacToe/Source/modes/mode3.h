#ifndef MODE3_H
#define MODE3_H
#include "ticTacToe_global.h"
#include <game.h>

class TICTACTOE_EXPORT Impossible: public QObject{
    Q_OBJECT
public:
    Impossible(QObject *parent = nullptr);
    ~Impossible();
};

#endif // MODE3_H
