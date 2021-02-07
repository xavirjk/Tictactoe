#include "mode2.h"
#include <QDebug>
#include <ctime>
#include <cstdlib>
Medium::Medium(QObject *parent)
    :QObject(parent){
    heapsort = new HeapSort(this);
}
Medium::~Medium(){}
int Medium::getSlot(const int progressArray[9],int progress, QString data) {
    int count = 0;
    staticProgress = progress;
    staticProgressArray = progressArray;
    if(data != "mode2"){
        defaultCount = ((8 - (staticProgress + 2))/2) + 1;
        statArr = new int[defaultCount];
        for(int i = 8; i > staticProgress; i--){
            if(i % 2 != 0){
                statArr[count] = staticProgressArray[i];
                count++;
            }
        }
        initializeMode();
        qDebug()<<"loop execution done, slot afta "<<slot;
        qDebug()<<"Final Slot for O"<<slot;
        return  slot;
    }

    defaultCount = ((8 - staticProgress)/2) + 1;
    statArr = new int[defaultCount];
    qDebug()<<"array Value:"<<defaultCount;

    for (int i = 8; i > staticProgress; i--){
        if(i % 2 == 0){
            statArr[count] = staticProgressArray[i];
            count += 1;
        }
    }
    initializeMode();
     qDebug()<<"Final Slot "<<slot;
     qDebug()<<progressArray[0]<<" "<<progressArray[1]<<" "<<progressArray[2]<<" "<<progressArray[3]<<" "<<progressArray[4]<<" "<<progressArray[5]<<" "<<progressArray[6]<<" "<<progressArray[7]<<" "<<progressArray[8];
     if(slot == -1)
         start_a_possibleWinningMove();
     else {
         int progCount = staticProgress + 1;
         for(int i = progCount; i <= 8; i++){
             if(staticProgressArray[i] == slot){
                 qDebug()<<"Match found at "<<i;
                 start_a_possibleWinningMove();
                 //slot = 0;
                 break;
             }
         }
     }
     if(staticProgress < 5){
         int tempSlot = slot;
         count = 0;
         defaultCount = ((8 - (staticProgress + 2))/2) + 1;
         statArr = new int[defaultCount];
         for(int i = 8; i > staticProgress; i--){
             if(i % 2 != 0){
                 statArr[count] = staticProgressArray[i];
                 count++;
             }
         }
         initializeMode();
         if(slot == -1){
            slot = tempSlot;
         }
         qDebug()<<"Final Slot for O"<<slot;
     }
     return slot;
}
void Medium::initializeMode(){
    statArr = heapsort ->heapSort(statArr,defaultCount);
    qDebug()<<"progress is::"<<staticProgress;
    qDebug()<<"Sorted ProgressArr";
    for(int i = 0; i < defaultCount; i++) {
        qDebug()<<"at "<<i<<":"<<statArr[i];
    }
    doubleInputsOperation();
    qDebug()<<"loop execution done, slot "<<slot;
}
void Medium::doubleInputsOperation(){
    int start;
    int trackStatArr = defaultCount - 2;
    slot = -1;
    for(int p  = defaultCount -1; p > 0; p-- ){
        temporaryPlayArray[1] = statArr[p];
        qDebug()<<"slot is"<<slot;
        if(slot != -1)
            break;

        for(int q = trackStatArr; q >= 0; q-- ){
            qDebug()<<"slot is"<<slot;
            if(slot != -1)
                break;

            int slotDiff = statArr[p] - statArr[q];
            qDebug()<<"Slot diff:"<<slotDiff;
            temporaryPlayArray[0] = statArr[q];

            if((statArr[q] % 3 == 0||slotDiff == 1)&& slotDiff < 3 && statArr[p] % 3 != 0){
              qDebug()<<"Checking row";
              setProp = slotDiff;// =1
              start = statArr[q] - 1;
              if(start % 3 == 0){
                  qDebug()<<"Start:"<<start;
                  slot = start;
              }
              else
                  closexHuman(start);

            }
            else if (slotDiff % 2 == 0 && statArr[q] % 2 == 0 && slotDiff != 6){
               qDebug()<<" check diag";
               if(statArr[q] + statArr[p] == 8)
                   slotDiff /= 2;
               setProp = slotDiff;
               start = statArr[q] - setProp;
               if(start == 0 && setProp == 4){
                   qDebug()<<" Start:"<<start;
                   slot = start;
               }
               else if(start == 2){
                   qDebug()<<" Start:"<<start;
                   slot = start;
               }
               else
                   closexHuman(start);

           }
            else if(slotDiff % 3 == 0){
                qDebug()<<"Checking col";
                setProp = 3;
                start = statArr[q] - 3;
                if(start < 3 && start >= 0){
                    qDebug()<<" Start:"<<start;
                    slot = start;
                }
                else
                    closexHuman(start);

            }
            if(slot != -1 && defaultCount >= 2){
                int progCount = staticProgress + 1;
                for(int i = progCount; i <= 8; i++){
                    if(staticProgressArray[i] == slot){
                        qDebug()<<"Match found at "<<i;
                        slot = -1;
                        break;
                    }
                }
            }
        }
        trackStatArr = trackStatArr - 1;
    }
    qDebug()<<"loop execution done, slot "<<slot;
}
void Medium::myFunction(int defaultOrigin, int i){
    for(int j = 0; j < 2; j++){
        if(defaultOrigin == statArr[j])
            break;
        if(defaultOrigin == staticProgressArray[i]){
            defaultOrigin+=boardIncrement;
            j-=1;
            continue;
        }
        if(j == 1)
            state = 1;
        slotsArr[j] = defaultOrigin;
        defaultOrigin+=boardIncrement;
    }
    confirmdataSets();
    qDebug()<<"SlotA:"<<slotsArr[0]<<" SlotB:"<<slotsArr[1];
}
void Medium::closexHuman(int start){
    for(int i = 0; i < 2; i++){
        start = start + setProp;
        if(start != temporaryPlayArray[i]){
            qDebug()<<" Start:"<<start;
            slot = start;
            break;
        }
        else if(i == 2 - 1){
            qDebug()<<" Start:"<<start + setProp;
            slot = start + setProp;
        }
    }
}
void Medium::start_a_possibleWinningMove(){
    state = 0;
    for(int i = 8; i > staticProgress; i--){
        qDebug()<<"start win move iterator:"<<i<<" state "<<state;
        if(i % 2 != 0 && !state){
            slotsArr = new int[defaultCount];
            for(int k = 0; k < defaultCount; k++)
                slotsArr[k] = -1;

            state = 0;
            qDebug()<<"done";
            //              SEARCH COLUMN
            int defaultOrigin = 0;
            boardIncrement = 3;
            if(staticProgressArray[i] < 3){
                defaultOrigin = staticProgressArray[i] - 0;
                myFunction(defaultOrigin,i);
            }
            else if(staticProgressArray[i] < 6 && staticProgressArray[i] >= 3){
                defaultOrigin = staticProgressArray[i] - 3;
                myFunction(defaultOrigin,i);
            }
            else {
                defaultOrigin = staticProgressArray[i] - 6;
                myFunction(defaultOrigin,i);
            }
            //                SEARCH ROW
            if(!state){
                boardIncrement = 1;
                if(staticProgressArray[i] < 3){
                    defaultOrigin = 0;
                    myFunction(defaultOrigin,i);
                }
                else if(staticProgressArray[i] > 2 && staticProgressArray[i] < 6){
                    defaultOrigin = 3;
                    myFunction(defaultOrigin,i);
                }
                else {
                    defaultOrigin = 6;
                    myFunction(defaultOrigin,i);
                }
            }
            if(!state && staticProgressArray[i] % 2 == 0){
                qDebug()<<"  Working for Diagonols ";
                int ref_point = staticProgressArray[i];
                if(ref_point == 4){
                    boardIncrement = 4;
                    myFunction(0,i);
                    if(!state){
                        boardIncrement = 2;
                        myFunction(2,i);
                    }
                }
                else if( ref_point== 0||ref_point == 8){
                   boardIncrement = 4;
                   myFunction(0,i);
                }
                else {
                    boardIncrement = 2;
                    myFunction(2,i);
                }
                /*srand(time(0));
                slot = rand()%(staticProgress + 1);
                qDebug()<<"steps to go, slot rand "<<slot;*/
                //Return Any empty slot
                //chance to access Diag
            }
            if(!state) {
                qDebug()<<"exeception execution";
                for(int i = 0; i <= staticProgress; i++){
                    qDebug()<<staticProgressArray[i];
                }
                srand(time(0));
                slot = staticProgressArray[rand()%staticProgress];
                state = 1;
                qDebug()<<"rand slot"<<slot;
            }
        }
    }
}
void Medium::confirmdataSets(){
    for(int k = 0; k < 2; k++){
        for(int l =0; l < defaultCount; l++){
            if(slotsArr[k] == statArr[l]){
                state = 0;
                break;
            }
        }
        if(k == 1)
            slot = slotsArr[0];
    }
}
