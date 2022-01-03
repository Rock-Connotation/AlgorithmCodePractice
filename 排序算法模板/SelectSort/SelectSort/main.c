//
//  main.c
//  SelectSort
//
//  Created by 石子涵 on 2022/1/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///随机生成指定数字范围内的数组
int* gennerateArrary(int maxSize, int maxValue, int* arrarySize);

///打印数组
void printArrary(int arrary[], int arraySize);

///交换
void swap(int *a, int *b);

///选择排序
void selectionSort(int arrary[], int arrarySize);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    //生成随机数种子，方便后面随机数调用
    srand((unsigned)time(NULL));
    int maxSize = 10;
    int maxValue = 1000;
    int arrarySize = maxSize;
    int *arrary = gennerateArrary(maxSize, maxValue, &arrarySize);
    
    printArrary(arrary, arrarySize);
    
    selectionSort(arrary, arrarySize);
    
    printArrary(arrary, arrarySize);
    return 0;
}

int* gennerateArrary(int maxSize, int maxValue, int *arrarySize){
    //创建目标数组
        //1.生成随机的数组长度,范围为（0 - maxSize）
    *arrarySize = rand() % maxSize + 1;
        //2.开辟数组空间
    int *arrary = (int *)malloc(sizeof(int) * *arrarySize);
        //3.填充-maxValue 到 maxvalue之间的数
    for (int i = 0; i < *arrarySize; i++) {
//        arrary[i] = (rand() % (maxSize + maxSize) + 1) - maxSize;
        arrary[i] = rand() % (maxSize + maxSize) + 1 - maxSize;
    }
    
    //返回
    return arrary;
}

void printArrary(int arrary[], int arraySize){
    if (arrary == NULL || arraySize == 0) {
        return;
    }
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", arrary[i]);
    }
    printf("\n");
}

void selectionSort(int arrary[], int arrarySize){
    if (arrary == NULL || arrarySize < 2) {
        return;
    }
    for (int i = 0; i < arrarySize; i++) {
        //选择最小点
        int minIndex = i;
        for (int j = i + 1; j < arrarySize; j++) {
            minIndex = arrary[j] < arrary[minIndex] ? j : minIndex;
        }
        swap(&arrary[i], &arrary[minIndex]);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

