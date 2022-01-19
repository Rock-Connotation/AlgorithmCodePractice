//
//  main.c
//  InsertionSort
//
//  Created by 石子涵 on 2022/1/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "Base.h"
///生成随机数
int * gennerateArrary(int maxSize, int maxValue, int *arrarySize);

///打印数组
void printArrary(int arrary[], int arrarySize);

void insertionSort(int arrary[], int arrarySize);

///交换数组中两个数的位置
void swap(int *a, int *b);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    //生成随机数种子
    srand((unsigned)time(NULL));
    int maxSize = 100;
    int maxValue = 10000;
    int arrarySize = maxSize;
    int* arrary = gennerateArrary(maxSize, maxValue, &arrarySize);
    printArrary(arrary, arrarySize);
    
    insertionSort(arrary, arrarySize);
    
    printArrary(arrary, arrarySize);
    
    return 0;
}

int * gennerateArrary(int maxSize, int maxValue, int *arrarySize){
    //创建目标数组
        //1.生成随机数组长度
    *arrarySize = rand() % maxSize + 1;
        //2.创建数组
    int *arrary = (int *)malloc(sizeof(int) * *arrarySize);
        //3，填充-maxValue到maxvalue区间的随机数
    for (int i = 0; i < *arrarySize; i++) {
        arrary[i] = rand() % ((maxValue + maxValue) + 1) - maxValue;
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

void insertionSort(int arrary[], int arrarySize){

    if (arrary == NULL || arrarySize < 2) {
        return;
    }
    for (int i = 1; i < arrarySize; i++) {
        for (int j = i - 1; j >= 0 && arrary[j] > arrary[j + 1]; j--) {
            swap(&arrary[j], &arrary[j + 1]);
        }
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
