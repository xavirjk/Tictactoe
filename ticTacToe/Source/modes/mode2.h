#ifndef MODE2_H
#define MODE2_H
#include "ticTacToe_global.h"
#include <depends/sort.h>
#include <QJsonArray>
#include <QObject>
class TICTACTOE_EXPORT Medium: public QObject{
public:
    Medium(QObject *parent = nullptr);
    ~Medium();
    int getSlot(const int progressArray[9],int progress);
    void start_a_possibleWinningMove(const int progressArray[9],int progress);
    void viewArr();
    int viewItem();
    void closexHuman(int start);
    void confirmdataSets();
    void myFunction(const int progressArray[9], int defaultOrigin, int i);
private:
    HeapSort *heapsort;
    int slot,boardIncrement;
    int setProp;
    bool state;
    int *slotsArr;
    int *statArr;
};

#endif // MODE2_H
