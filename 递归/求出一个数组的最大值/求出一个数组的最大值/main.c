//
//  main.c
//  求出一个数组的最大值
//
//  Created by 石子涵 on 2021/12/30.
//

#include <stdio.h>
int process(int arrary[], int L, int R);


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int arrary[10] = {1,3,4,100,20,78,25,32,18,10};
    int max = process(arrary, 0, 9);
    printf("%d\n",max);
    return 0;
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
