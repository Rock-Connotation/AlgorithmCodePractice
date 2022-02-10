//
//  main.c
//  打印一个数的32位
//
//  Created by 石子涵 on 2022/2/9.
//

#include <stdio.h>
void printBit(int num);

///求n的阶乘
int factorial(int n);

int main(int argc, const char * argv[]) {
    
//    int a = 9;
//    int b = 23;
//    printBit(a);
//    printBit(b);
//    printf("=======\n");
//    printBit(a | b);
    
    //取反
//    int a = 5;
//    int b = -a;
//    int c = ~a + 1;
//    printf("%d   %d\n", b, c);
    printf("%d\n", factorial(3));
    return 0;
}
void printBit(int num){
    for (int i = 0; i < 32; i++) {
        int a = ((num & (1 << i)) == 0) ? 0 : 1;
        printf("%d ",a);
    }
    printf("\n");
}

int factorial(int n){
    int cur = 1;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cur =  i * cur;
        res += cur;
    }
    return res;
}
