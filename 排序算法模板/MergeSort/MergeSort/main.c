//
//  main.c
//  MergeSort
//
//  Created by 石子涵 on 2022/1/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int* gennerateArrary(int maxSize, int maxValue, int *arrarySize);

void printArrary(int ary[], int arySize);

void mergeSortFirst(int ary[], int arySize);

void mergeSortSecond(int ary[], int l, int r);

void merge(int ary[], int l, int r, int mid);

void swap(int *a, int *b);

int main(int argc, const char * argv[]) {
    //生成随机数种子
    srand((unsigned)time(NULL));
    int maxSize = 10;
    int maxValue = 10000;
    int arySize = maxSize;
    int *ary = gennerateArrary(maxSize, maxValue, &arySize);
    
    printArrary(ary, arySize);
    
    mergeSortFirst(ary, arySize);
    
    printArrary(ary, arySize);
    
    return 0;
}

int* gennerateArrary(int maxSize, int maxValue, int *arrarySize){
    *arrarySize = rand() % maxSize + 1;
    int *ary = (int *)malloc(sizeof(int) * *arrarySize);
    for (int i = 0; i < *arrarySize; i++) {
        ary[i] = rand() % (maxValue*2 + 1) - maxValue;
    }
    return ary;
}

void printArrary(int ary[], int arySize){
    if (ary == NULL || arySize == 0) {
        return;
    }
    for (int i = 0; i < arySize; i++) {
        printf("%d ",ary[i]);
    }
    printf("\n");
}

void mergeSortFirst(int ary[], int arySize){
    if (ary == NULL || arySize < 2) {
        return;
    }
    mergeSortSecond(ary, 0, arySize - 1);
}

void mergeSortSecond(int ary[], int l, int r){
    //结束递归条件
    if (l == r) {
        return;
    }
    int mid = l + ((r - l) >> 1);
    mergeSortSecond(ary, l, mid);
    mergeSortSecond(ary, mid + 1, r);
    merge(ary, l, r, mid);
}

void merge(int ary[], int l, int r, int mid){
    int *help = (int *)malloc(sizeof(int) * (r - l + 1));
    int i = 0;
    int p1 = l;
    int p2 = mid + 1;
    while (p1 <= mid && p2 <= r) {
        help[i++] = ary[p1] < ary[p2] ? ary[p1++] : ary[p2++];
    }
    
    while (p1 <= mid) {
        help[i++] = ary[p1++];
    }
    
    while (p2 <= r) {
        help[i++] = ary[p2++];
    }
    
    for (int i = 0; i < (r-l+1); i++) {
        ary[l + i] = help[i];
    }
    free(help);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
