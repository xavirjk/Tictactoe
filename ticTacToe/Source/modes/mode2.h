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
    int getSlot(const int progressArray[9],int progress, QString data);
    void start_a_possibleWinningMove();
    void closexHuman(int start);
    void confirmdataSets();
    void doubleInputsOperation();
    void initializeMode();
    void myFunction(int defaultOrigin, int i);
    int interfaceInitializeMode(const int progressArray[9],int progress);
private:
    HeapSort *heapsort;
    const int *staticProgressArray;
    int *slotsArr;
    int *statArr;
    int temporaryPlayArray[2];
    int slot = -1
       , boardIncrement;
    int defaultCount = 0
       , staticProgress;
    int setProp;
    bool state;

};

#endif // MODE2_H
