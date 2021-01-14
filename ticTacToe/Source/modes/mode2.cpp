#include "mode2.h"
#include <QDebug>
Medium::Medium(QObject *parent)
    :QObject(parent){
    heapsort = new HeapSort(this);
}
Medium::~Medium(){}
int Medium::getSlot(const int progressArray[9],int progress) {
    statArr = new int[((8 - progress)/2) + 1];
    qDebug()<<"array Value:"<<((8 - progress)/2) + 1;
    int start;
    int count = 0;
    for (int i = 8; i > progress; i--){
        if(i % 2 == 0){
            statArr[count] = progressArray[i];
            count += 1;
        }
    }
    statArr = heapsort->heapSort(statArr,((8 - progress)/2) + 1);
    qDebug()<<"Sorted ProgressArr";
    for(int i = 0; i < ((8 - progress)/2) + 1; i++) {
        qDebug()<<"at "<<i<<":"<<statArr[i];
    }
    //Start working out the combinations
    int slotDiff = statArr[1] - statArr[0];
    slot = -1;
     qDebug()<<" slot Diff:"<<slotDiff<<" current slot:"<<slot;
     if((statArr[0] % 3 == 0||slotDiff == 1)&& slotDiff < 3 && statArr[1] % 3 != 0){
       qDebug()<<"Checking row";
       setProp = slotDiff;// =1
       start = statArr[0] - 1;
       if(start % 3 == 0){
           qDebug()<<"Start:"<<start;
           slot = start;
       }
       else {
           closexHuman(start);
       }
     }
     else if (slotDiff % 2 == 0 && statArr[0] % 2 == 0 && slotDiff != 6){
        qDebug()<<" check diag";
        if(statArr[0] + statArr[1] == 8)
            slotDiff /= 2;
        setProp = slotDiff;
        start = statArr[0] - setProp;
        if(start == 0 && setProp == 4){
            qDebug()<<" Start:"<<start;
            slot = start;
        }
        else if(start == 2){
            qDebug()<<" Start:"<<start;
            slot = start;
        }
        else {
            closexHuman(start);
        }
    }
     else if(slotDiff % 3 == 0){
         qDebug()<<"Checking col";
         setProp = 3;
         start = statArr[0] - 3;
         if(start < 3 && start >= 0){
             qDebug()<<" Start:"<<start;
             slot = start;
         }
         else {
             closexHuman(start);
         }
     }
     qDebug()<<"Final Slot "<<slot;
     qDebug()<<progressArray[0]<<" "<<progressArray[1]<<" "<<progressArray[2]<<" "<<progressArray[3]<<" "<<progressArray[4]<<" "<<progressArray[5]<<" "<<progressArray[6]<<" "<<progressArray[7]<<" "<<progressArray[8];
     if(slot == -1){
         start_a_possibleWinningMove(progressArray,progress);
         //slot = 0;
     }
     else {
         int progCount = progress + 1;
         for(int i = progCount; i <= 8; i++){
             if(progressArray[i] == slot){
                 qDebug()<<"Match found at "<<i;
                 start_a_possibleWinningMove(progressArray,progress);
                 //slot = 0;
                 break;
             }
         }
     }
     return slot;
}
void Medium::myFunction(const int *progressArray, int defaultOrigin, int i){
    for(int j = 0; j < 2; j++){
        if(defaultOrigin == statArr[j])
            break;
        if(defaultOrigin == progressArray[i]){
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
        if(start != statArr[i]){
            qDebug()<<" Start:"<<start;
            slot = start;
            break;
        }
        else if(i == 1){
            qDebug()<<" Start:"<<start + setProp;
            slot = start + setProp;
        }
    }
}
void Medium::start_a_possibleWinningMove(const int *progressArray, int progress){
    for(int i = 8; i > progress; i--){
        if(i % 2 != 0){
            slotsArr = new int[2];
            for(int k = 0; k < 2; k++){
                slotsArr[k] = -1;
            }
            state = 0;
            qDebug()<<"done";
            //              SEARCH COLUMN
            int defaultOrigin = 0;
            boardIncrement = 3;
            if(progressArray[i] < 3){
                defaultOrigin = progressArray[i] - 0;
                myFunction(progressArray,defaultOrigin,i);
            }
            else if(progressArray[i] < 6 && progressArray[i] >= 3){
                defaultOrigin = progressArray[i] - 3;
                myFunction(progressArray,defaultOrigin,i);
            }
            else {
                defaultOrigin = progressArray[i] - 6;
                myFunction(progressArray,defaultOrigin,i);
            }
            //                SEARCH ROW
            if(!state){
                boardIncrement = 1;
                if(progressArray[i] < 3){
                    defaultOrigin = 0;
                    myFunction(progressArray,defaultOrigin,i);
                }
                else if(progressArray[i] > 2 && progressArray[i] < 6){
                    defaultOrigin = 3;
                    myFunction(progressArray,defaultOrigin,i);
                }
                else {
                    defaultOrigin = 6;
                    myFunction(progressArray,defaultOrigin,i);
                }
            }
            if(!state){
                qDebug()<<"steps to go";
                slot = 0;
                //chance to access Diag
            }
        }
    }
}
void Medium::confirmdataSets(){
    for(int k = 0; k < 2; k++){
        for(int l =0; l < 2; l++){
            if(slotsArr[k] == statArr[l]){
                state = 0;
                break;
            }
        }
        if(k == 1)
            slot = slotsArr[0];
    }
}
void Medium::viewArr(){
 qDebug()<<"my arr";
}
int Medium::viewItem(){
    return 4;
}
