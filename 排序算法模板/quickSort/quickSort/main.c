//
//  main.c
//  quickSort
//
//  Created by 石子涵 on 2022/1/23.
//

#include <stdio.h>
#include "Base.h"

void quickSortFirst(int *ary, int arySize);

void quickSortSecond(int *ary, int l, int r);

int* partation(int *ary, int l, int r);


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int arySize = 0;
    int *ary = gennerateArrary(15 , 10, &arySize);
    printArrary(ary, arySize);

    
    quickSortFirst(ary, arySize);
    printArrary(ary, arySize);
    return 0;
}

void quickSortFirst(int *ary, int arySize){
    if (ary == NULL || arySize < 2) {
        return;
    }
    quickSortSecond(ary, 0, arySize - 1);
}

void quickSortSecond(int *ary, int l, int r){
    if (l < r) {
//        swap(&ary[rand()%(r + 1 - l)], &ary[r]);
        int *tempAry = partation(ary, l, r);
        quickSortSecond(ary, l, tempAry[0] - 1);
        quickSortSecond(ary, tempAry[1] + 1, r);
    }
}

int* partation(int *ary, int l, int r){
    int less =  l - 1;  //小于区域
    int more = r;       //大于区域
    //r是进行
    while(l < more) {
        if (ary[l] < ary[r]) {
            swap(&ary[++less], &ary[l++]); //扩大小于区域，并且l左移
        }else if(ary[l] > ary[r]){
            swap(&ary[l], &ary[--more]);
        }else{
            l++;
        }
    }
    swap(&ary[more], &ary[r]);
    //数组返回的是中间的左右下标
    int *temp = malloc(sizeof(int) * 2);
    temp[0] = less + 1;
    temp[1] = more;
    return temp;
}
