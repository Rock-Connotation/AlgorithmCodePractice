//
//  Base.c
//  InsertionSort
//
//  Created by 石子涵 on 2022/1/13.
//

#include "Base.h"

int * gennerateArrary(int maxSize, int maxValue, int *arrarySize){
    //创建目标数组
        //1.生成随机数组长度
    *arrarySize = rand() % maxSize + 1;
        //2.创建数组
    int *arrary = (int *)malloc(sizeof(int) * *arrarySize);
        //3，填充-maxValue到maxvalue区间的随机数
    for (int i = 0; i < *arrarySize; i++) {
//        arrary[i] = rand() % ((maxValue + maxValue) + 1) - maxValue;
        arrary[i] = rand() % maxValue + 1;
    }
    
    //返回
    return arrary;
}

void printArrary(int arrary[], int arrarySize){
    if (arrary == NULL || arrarySize == 0) {
        return;
    }
    for (int i = 0; i < arrarySize; i++) {
        printf("%d ", arrary[i]);
    }
    printf("\n");
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
