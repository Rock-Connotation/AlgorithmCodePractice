//
//  main.c
//  二分查找求数组中=num的最左位置
//
//  Created by 石子涵 on 2022/2/10.
//

#include <stdio.h>
int binaryLeftNum(int *ary, int arySize, int num);

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    int ary[] = {1,2,3,3,4,4,6};
    printf("%d\n",binaryLeftNum(ary, 7, 4));
    return 0;
}
int binaryLeftNum(int *ary, int arySize, int num){
    if (ary == NULL || arySize == 0) {
        return -1;
    }
    if (arySize < 2) {
        return ary[0] == num ? 0 : -1;
    }
    int res = -1;
    int l = 0, r = arySize - 1;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (ary[mid] >= num) {
            res = mid;
            r = mid - 1;
        }else if(ary[mid] < num){
            l = mid + 1;
        }
    }
    
    return res;
}
