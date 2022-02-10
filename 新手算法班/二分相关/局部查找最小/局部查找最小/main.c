//
//  main.c
//  局部查找最小
//
//  Created by 石子涵 on 2022/2/10.
//

#include <stdio.h>
int localMin(int *ary, int arySize);
int main(int argc, const char * argv[]) {
    int ary[7] = {2,2,4,8,6,7};
    printf("%d\n",localMin(ary, 6));
    printf("Hello, World!\n");
    
    return 0;
}
int localMin(int *ary, int arySize){
    if (ary == NULL || arySize == 0) {
        return -1;
    }
    if (arySize == 1) {
        return 0;
    }
    if (ary[0] < ary[1]) {
        return 0;
    }
    if (ary[arySize - 1] < ary[arySize - 2]) {
        return arySize - 1;
    }
    int l = 0;
    int r = arySize - 1;
    while (l < r - 1) {
        int mid = l + ((r - l) >> 1);
        if (ary[mid] < ary[mid - 1] && ary[mid] < ary[mid + 1]) {
            return mid;
        }else{
            if (ary[mid] > ary[mid - 1]) {
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
    }
    return ary[l] < ary[r] ? l : r ;
}
