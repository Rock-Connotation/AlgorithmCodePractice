//
//  main.c
//  数组中的逆序对
//
//  Created by 石子涵 on 2022/1/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "Base.h"
int reversePairs(int* nums, int numsSize);

int process(int *ary, int l, int r);

//排序求逆序对
int merge(int *ary, int l, int mid, int r);

int comparator(int *ary, int arySize);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int arySize = 10;
    int *ary = gennerateArrary(10, 10, &arySize);
    printArrary(ary, arySize);
    printf("%d\n", comparator(ary, arySize));
    printf("%d\n", reversePairs(ary, arySize));
    return 0;
}

int reversePairs(int* nums, int numsSize){
    if(nums == NULL || numsSize < 2){
        return 0;
    }
    return process(nums, 0 , numsSize - 1);
}

int process(int *ary, int l, int r){
    if(l == r){
        return 0;
    }
    int mid = l + ((r - l) >> 1);
    //左边逆序对 + 右边逆序对 + 排序逆序对，不重不漏
    return process(ary, l, mid) + process(ary, mid + 1, r) + merge(ary, l , mid, r);
}
int merge(int *ary, int l, int mid, int r){
    int *helpAry = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l;
    int p2 = mid + 1;
    int i = 0;
    int sum = 0;
    while(p1 <= mid && p2 <= r ){
        sum += ary[p1] > ary[p2] ? (mid - p1 + 1) : 0;
        //当左右边数字相等的时候，先拷贝左边的数
        helpAry[i++] = ary[p1] <= ary[p2] ? ary[p1++] : ary[p2++];
    }
    while(p1 <= mid){
        helpAry[i++] = ary[p1++];
    }
      while(p2 <= r){
        helpAry[i++] = ary[p2++];
    }

    for(int i = 0; i < (r - l + 1); i++){
        ary[l + i] = helpAry[i];
    }
    // free(helpAry);
    return sum;
}

//int merge(int *ary, int l, int mid, int r){
//    int *help = (int *)malloc(sizeof(int) * (r - l + 1));
//    int p1 = l;
//    int p2 = mid + 1;
//    int i = 0;
//    int sum = 0;
//    while (p1 <= mid && p2 <= r) {
//        //求小和:右边比左边大的总数 * 左边的数
//        sum += ary[p1] > ary[p2] ? ( mid - p1 + 1) : 0;
//
//        //左边和右边的数相等时，一定要先拷贝右边的数到辅助数组里面
//        help[i++] = ary[p1] <= ary[p2] ? ary[p1++] : ary[p2++];
//    }
//
//    while(p1 <= mid){
//        help[i++] = ary[p1++];
//    }
//
//    while (p2 <= r) {
//        help[i++] = ary[p2++];
//    }
//
//    for (int i = 0; i < r - l + 1; i++) {
//        ary[l + i] = help[i];
//    }
//
//    return sum;
//}


int comparator(int *ary, int arySize){
//    int sum = 0;
//    for (int i = 0; i < arySize; i++) {
//        for (int j = 0; j < i; j++) {
//            sum += ary[j] > ary[i] ? 1 : 0;
//        }
//    }
//    return sum;
    
    int sum = 0;
    for (int i = 0; i < arySize; i++) {
        for (int j = i; j < arySize; j++) {
            sum += ary[j] < ary[i] ? 1 : 0;
        }
    }
    return sum;
}
