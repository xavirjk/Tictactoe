#ifndef MODE_CONTROLLER_H
#define MODE_CONTROLLER_H

#include "ticTacToe_global.h"
#include <modes/mode2.h>
class TICTACTOE_EXPORT ModeController: public QObject{
    Q_OBJECT
public:
    ModeController(QObject *parent = nullptr);
    ~ModeController();
    int mode2Slot (const int progressArray[9],int progress, QString data);
private:
    Medium *mode2;
};


#endif // MODE_CONTROLLER_H
