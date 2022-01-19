//
//  main.c
//  归并排序迭代版
//
//  Created by 石子涵 on 2022/1/17.
//

#include <stdio.h>
#include <stdlib.h>

void MergeSort(int k[], int n);
int main(int argc, const char * argv[]) {
  
    
    return 0;
}

void MergeSort(int k[], int n){
    int i, next, left_min, left_max, right_min, right_max;
    int *temp = (int *)malloc(n * sizeof(int));
 
    //i 为步长， 1， 2， 4， 8...
    for( i = 1; i < n; i *= 2 ){
        //从0开始，根据步长，向右分组排序
        for( left_min = 0; left_min < n-i; left_min = right_max ){
            right_min = left_max = left_min + i;
            right_max = left_max + i;
            
            if( right_max > n ){
                right_max = n;
            }
            
            next = 0;
            
            //将k[]数组中小的数据备份到temp[]数组中，
            //结束条件是left部分或者right部分有一个已经完全拷贝到temp[]中
            while( left_min < left_max && right_min < right_max ){
                if( k[left_min] < k[right_min] ){
                    temp[next++] = k[left_min++];
                }else{
                    temp[next++] = k[right_min++];
                }
            }
            
            //现在k[]数组中没有备份的都是大的数据，有两种可能性，
            //一种是left部分拷贝完成，另一种可能性是right部分拷贝完成,对于后一种情况，
            //无需考虑，因为right部分本来就排在k[]数组中靠后的位置，
            //也就是存放大数据的位置，这里只需要考虑第一种情况，将left部分的较大的数据，从k[left_max]，开始，
            //覆盖到k[right_min]的位置（k[right_min]中的数据上一部已经拷贝到temp[]数组中）
            while( left_min < left_max ){
                k[--right_min] = k[--left_max];
            }
            
            //，将temp[]数组中备份的数据重新拷贝回k[]数组中
            while( next > 0 ){
                k[--right_min] = temp[--next];
            }
        }
    }
}


