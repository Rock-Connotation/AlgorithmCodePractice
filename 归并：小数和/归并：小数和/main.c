//
//  main.c
//  归并：小数和
//
//  Created by 石子涵 on 2022/1/19.
//

#include <stdio.h>
#include "Base.h"
int smallSum(int *ary, int arySize);
int process(int *ary, int l, int r);
int merge(int *ary, int l, int mid, int r);

int comparator(int *ary, int arySize);
int main(int argc, const char * argv[]) {
    int arySize = 10;
    int *ary = gennerateArrary(10, 10, &arySize);
//   int ary[] = {7,5,6,4};
//    arySize = 4;
    printArrary(ary, arySize);
    
    printf("%d\n", comparator(ary, arySize));
    int sum = smallSum(ary, arySize);
//    printArrary(ary, arySize);
    printf("%d\n", sum);
    
    
    return 0;
}

int smallSum(int *ary, int arySize){
    if (ary == NULL || arySize < 2) {
        return 0;
    }
    return process(ary, 0, arySize - 1);
}

int process(int *ary, int l, int r){
    if (l == r) {
        return 0;
    }
    int mid = l + ((r - l) >> 1);
    //返回 左边的小数和 + 右边的小数和 + 合并的小数和
    return process(ary, l, mid) + process(ary, mid + 1, r) + merge(ary, l, mid, r);
}
//既要排好序，又要求小和
int merge(int *ary, int l, int mid, int r){
    int *help = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l;
    int p2 = mid + 1;
    int i = 0;
    int sum = 0;
    while (p1 <= mid && p2 <= r) {
        //求小和:右边比左边大的总数 * 左边的数
        sum += ary[p1] < ary[p2] ? ((r - p2 + 1) * ary[p1]) : 0;

        //左边和右边的数相等时，一定要先拷贝右边的数到辅助数组里面
        help[i++] = ary[p1] < ary[p2] ? ary[p1++] : ary[p2++];
    }

    while(p1 <= mid){
        help[i++] = ary[p1++];
    }

    while (p2 <= r) {
        help[i++] = ary[p2++];
    }

    for (int i = 0; i < r - l + 1; i++) {
        ary[l + i] = help[i];
    }

    return sum;
}

//求逆序对的
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
    int sum = 0;
    for (int i = 0; i < arySize; i++) {
        for (int j = 0; j < i; j++) {
            sum += ary[j] < ary[i] ? ary[j] : 0;
        }
    }
    return sum;
}

////求逆序对
//int comparator(int *ary, int arySize){
//    int sum = 0;
//    for (int i = 0; i < arySize; i++) {
//        for (int j = i; j < arySize; j++) {
//            sum += ary[j] < ary[i] ? 1 : 0;
//        }
//    }
//    return sum;
//}
