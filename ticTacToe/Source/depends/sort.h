#ifndef SORT_H
#define SORT_H

#include "ticTacToe_global.h"
#include <QObject>

class TICTACTOE_EXPORT HeapSort: public QObject
{
public:
    HeapSort(QObject *parent = nullptr);
    ~HeapSort();

    void createMax_Heap(int len);
    void max_Heapify(int i, int n);
    void sort_MaxHeap(int n);
    void swap(int a, int b);
    int  *heapSort(int *staticArr, int len);
private:
    int *dataset;
};

#endif // SORT_H
