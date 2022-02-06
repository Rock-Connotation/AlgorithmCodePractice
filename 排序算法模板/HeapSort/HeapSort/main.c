//
//  main.c
//  HeapSort
//
//  Created by 石子涵 on 2022/1/27.
//

/**
 思路：
1.构成一个大根堆，可以heapInsert，或者逆向heapify
2.依次将堆的最后一个元素和堆顶元素交互，将最后一个元素，弹出heapSize--，重复这个过程
 */
#include <stdio.h>
#include "Base.h"
void heapSory(int *ary, int arySize);

void heapInsert(int *ary, int index);

void heapify(int *ary, int index, int size);
int main(int argc, const char * argv[]) {
 
    return 0;
}

void heapSory(int *ary, int arySize){
    if (ary == NULL || arySize < 2) {
        return;
    }
    for (int i = 0; i < arySize; i++) {
        heapInsert(ary, i);
    }
    
    //管理堆长度
    int heapSize = arySize;
    swap(ary, ary+(--heapSize));
    
    while (heapSize > 0) {
        heapify(ary, 0, heapSize);
        swap(ary, ary+(--heapSize));
    }
}

void heapInsert(int *ary, int index){
    //如果此节点的值大于父节点的的值，则进行交换
    while (ary[index] > ary[(index - 1) / 2]) {
        swap(ary + index, ary + ((index - 1)/2));
        index = (index - 1) / 2;
    }
}

void heapify(int *ary, int index, int size){
    int left = index * 2 + 1;   //左孩子
    
}
