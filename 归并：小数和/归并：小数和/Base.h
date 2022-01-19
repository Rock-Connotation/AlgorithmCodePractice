//
//  Base.h
//  InsertionSort
//
//  Created by 石子涵 on 2022/1/13.
//

#ifndef Base_h
#define Base_h

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
///生成随机数
int * gennerateArrary(int maxSize, int maxValue, int *arrarySize);

///打印数组
void printArrary(int arrary[], int arrarySize);

///交换数组中两个数的位置
void swap(int *a, int *b);
#endif /* Base_h */
