//
//  main.c
//  二分查找有序数组中<=num最右的位置
//
//  Created by 石子涵 on 2022/2/10.
//

#include <stdio.h>
int binaryRightNum(int *ary, int arySize, int num);
int main(int argc, const char * argv[]) {
    // insert code here...
    int ary[] = {1,2,4,4,4,4,5,5,5,5,6};
    
    printf("%d\n", binaryRightNum(ary, 10
                                  , 5));
    return 0;
}
int binaryRightNum(int *ary, int arySize, int num){
    int l = 0;
    int r = arySize - 1;
    int rightIndex = -1;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (ary[mid] > num) {
            r = mid - 1;
        }else{
            rightIndex = mid;
            l = mid + 1;
        }
    }
    return rightIndex;
}
