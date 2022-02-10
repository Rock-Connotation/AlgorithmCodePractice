//
//  main.c
//  从随机1-5到随机数1-7
//
//  Created by 石子涵 on 2022/2/10.
//

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
///随机返回1-5的数
int f1(void);
///0、1对数器
int f2(void);

///返回0-7的等概率随机数
int f3(void);

//返回1-7的等概率随机数
int f4(void);

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    for (int i = 0;i < 100 ; i++) {
        printf("%d", f4());
    }
    printf("\n");
    return 0;
}

int f1(void){
    return rand()%5 + 1;
}

int f2(void){
    int ans = 0;
    do{
        ans = f1();
    }while(ans == 3);
    return ans < 3 ? 0 : 1;
}

int f3(void){
    int res = (f2() << 2) + (f2() << 1) + f2();
    return res;
}

int f4(void){
    int res = 0;
    do{
        res = f3() + 1;
    }while(res == 8);
    return res;
}
