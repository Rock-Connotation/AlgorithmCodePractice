//
//  main.c
//  二分查找
//
//  Created by 石子涵 on 2022/2/10. 
//

#include <stdio.h>
#include "Base.h"
void insertSorting(int *ary, int arySize);
int binarySearch(int *ary, int arySize, int num);
int main(int argc, const char * argv[]) {
    int arySize = 0;
    int *ary = gennerateArrary(10, 10, &arySize);
    printArrary(ary, arySize);
    insertSorting(ary, arySize);
    printArrary(ary, arySize);
    int a = ary[rand()%arySize];
    printf("%d  %d\n", a, binarySearch(ary, arySize, a));
    
    return 0;
}

void insertSorting(int *ary, int arySize){
    if (ary == NULL || arySize < 2) {
        return;
    }
    
    for (int i = 1; i < arySize; i++) {
        for (int j = i; j - 1 >= 0 && ary[j - 1] > ary[j]; j--) {
            swap(&ary[j - 1], &ary[j]);
        }
    }
}
int binarySearch(int *ary, int arySize, int num){
//    int res = 0;
    if (ary == NULL || arySize == 0) {
        return 0;
    }
    if (arySize < 2) {
        return num == ary[0] ? 1 : 0;
    }
    int l = 0, r = arySize - 1;
    int mid = l + ((r - l) >> 1);
    while ( l <= r) {
        mid = l + ((r - l) >> 1);
        if (ary[mid] > num) {
            r = mid - 1;
        }else if(ary[mid] < num){
            l = mid + 1;
        }else{
            return 1;
        }
    }
    return 0;
}
