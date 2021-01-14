#include "sort.h"
HeapSort::HeapSort(QObject *parent)
    :QObject(parent){

}
HeapSort::~HeapSort(){}

void HeapSort::swap(int a, int b){
    int temp = dataset[a];
    dataset[a] = dataset[b];
    dataset[b] = temp;
}
void HeapSort::createMax_Heap(int len){
    for(int i = len/2-1; i >= 0; i--){
            max_Heapify(i,len);
        }
}

void HeapSort::max_Heapify(int i, int n){
    int largest=i;
        int left=(2*i)+1;
        int right=(2*i)+2;
        //If left child is larger than Root
        if( left < n && dataset[left] > dataset[largest] ){
            largest=left;
        }
        //if right child is larger than largest So far
        if(right < n && dataset[right] > dataset[largest] ){
            largest=right;
        }
        if(largest !=i ){
            swap(i,largest);
            max_Heapify(largest,n);
        }
}
void HeapSort::sort_MaxHeap(int n){
    for(int i = n - 1; i >= 0; i--){
                swap(0,i);
                createMax_Heap(i);
        }
}
int *HeapSort::heapSort(int *staticArr, int len){
    dataset = new int[len];
    for(int i = 0; i < len; i++){
        dataset[i] = staticArr[i];
    }
    createMax_Heap(len);
    sort_MaxHeap(len);
    return dataset;
}
