//
//  main.c
//  对数器
//
//  Created by 石子涵 on 2021/12/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///产生一个长度随机，内容随机的数组
int* generateRandomArrary(int maxSize, int maxValue, int* arrarySize);

///复制一个相同的数组
int * copyArrary(int arrary[], int arrarySize);

///比对两个数组是否相等
int isEqual(int arr1[], int arraySize1, int arr2[], int arraySize2);

///打印数组
void printArrary(int arrary[], int arrarySize);

///要测试的方法  递归找出一个数组的最大值
int process(int arrary[], int L, int R);

///比较的方法
int comparator(int array[], int arraySize);

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));    //生成随机数种子，方便后面的rand函数调用，不然就是伪随机数
    int testTime = 1000;   //测试次数
    int maxSize = 100;      //测试数组最大长度
    int maxValue = 10000;   //测试数组的最大值
    int succeed = 1;    //比对结果

    for (int i = 0; i < testTime; i++) {
        //原始数组
        int arraySizeOrigin = maxSize;
        int* ary1 = generateRandomArrary(maxSize, maxValue, &arraySizeOrigin);

        //拷贝后的数组
        int arraySizeNew = arraySizeOrigin;
        int* ary2 = copyArrary(ary1, arraySizeNew);

        int a = process(ary1, 0, arraySizeOrigin - 1);
        int b = comparator(ary2, arraySizeNew);
        
        
        
        if (a != b) {
            succeed = 0;
            printf("%d\t, %d", a, b);
            printArrary(ary1, arraySizeOrigin);
            printArrary(ary2, arraySizeNew);
            break;
        }
    }
    
    if (succeed) {
        printf("you are the best!\n");
    }else{
        printf("fuck!\n");
    }
    
    int a = 1;
    int *p = &(++a);
    printf("%p, %p\n", &a, p);
    
    return 0;
}

int* generateRandomArrary(int maxSize, int maxValue, int* arrarySize){
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

int * copyArrary(int arrary[], int arrarySize){
    if (arrary == NULL) {
        return NULL;
    }
    
    //创建目标随机数组
    int *ary = (int *)malloc(sizeof(int) * arrarySize);
    for (int i = 0; i < arrarySize; i++) {
        ary[i] = arrary[i];
    }
    return ary;
}

int isEqual(int arr1[], int arraySize1, int arr2[], int arraySize2){
    
    if ((arr1 == NULL && arr2 != NULL) || (arr1 != NULL && arr2 == NULL)) {
        return 0;
    }
    
    //两个数组都为空则也相等
    if (arr1 == NULL && arr2 == NULL) {
        return 1;
    }
    
    //数组长度不相等则也不相等
    if (arraySize1 != arraySize2) {
        return 0;
    }
    
    //挨个比对，如果任一不相等则失败
    for (int i = 0; i < arraySize1; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

void printArrary(int arrary[], int arrarySize){
    if (arrary == NULL) {
        return;
    }
    
    for (int i = 0; i < arrarySize; i++) {
        printf("%d\t", arrary[i]);
    }
    
    printf("\n");
}

int process(int arrary[], int L, int R){
    if (L == R) {
        return arrary[L];
    }
    int mid = L + ((R - L) >> 1);
    int leftMax = process(arrary, L, mid);
    int rightMax = process(arrary, mid + 1, R);
    return leftMax >= rightMax ? leftMax : rightMax;
}

///比较的方法
int comparator(int array[], int arraySize){
    int max = array[0];
    for (int i = 0; i < arraySize; i++) {
        if (max <= array[i]) {
            max = array[i];
        }
    }
    return max;
}
