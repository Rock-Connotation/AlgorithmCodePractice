//
//  main.c
//  BubbleSort
//
//  Created by 石子涵 on 2022/1/3.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
///冒泡排序
void bubbleSort(int arrary[], int arrarySize);

///交换数组中两个数的位置
//void swap(int arrary[], int i, int j);
void swap(int *a, int *b);

///产生一个长度随机，内容随机的数组
int* generateRandomArrary(int maxSize, int maxValue, int* arrarySize);

///打印数组
void printArrary(int arrary[], int arrarySize);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int maxSize = 10;
    int maxValue = 10000;
    int arraySizeOrigin = maxSize;
    int* arrary = generateRandomArrary(maxSize, maxValue, &arraySizeOrigin);
    printArrary(arrary, arraySizeOrigin);
    bubbleSort(arrary, arraySizeOrigin);
    printArrary(arrary, arraySizeOrigin);
    return 0;
}

void bubbleSort(int arrary[], int arrarySize){
    if (arrary == NULL || arrarySize == 0) {
        return;
    }
    for (int i = arrarySize; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arrary[j] > arrary[j + 1]) {
                swap(arrary+j, arrary+j+1);
            }
        }
    }
    printf("\n");
}

///交换数组中两个数的位置
//void swap(int arrary[], int i, int j){
//    arrary[i] = arrary[i] ^ arrary[j];
//    arrary[j] = arrary[i] ^ arrary[j];
//    arrary[i] = arrary[i] ^ arrary[j];
//}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* generateRandomArrary(int maxSize, int maxValue, int* arrarySize){
    //生成随机数种子，方便后面的rand函数调用，不然就是伪随机数
    srand((unsigned)time(NULL));
    
    //创建目标随机数组
        //生成随机的数组长度
    *arrarySize = rand() % maxSize + 1;
        //开辟数组空间
    int *arrary = (int *)malloc(sizeof(int) * *arrarySize);
    
    for (int i = 0; i < *arrarySize; i++) {
        //生成-maxValue到maxValue之间的随机数
        arrary[i] = (rand() % (maxValue+maxValue) + 1) - maxValue;
    }
    
////    //测试打印
//    for (int i = 0; i < *arrarySize; i++) {
//        printf("%d\n",arrary[i]);
//    }
//    printf("\n");
    return arrary;
}

void printArrary(int arrary[], int arrarySize){
    if (arrary == NULL && arrarySize == 0) {
        return;
    }
    
    for (int i = 0; i < arrarySize; i++) {
        printf("%d ", arrary[i]);
    }
    
    printf("\n");
}
