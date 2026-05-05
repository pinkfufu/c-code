//
// Created by ZhangYao on 2026/5/5.
//
#include <stdio.h>

#define N 5

int pMax(int *p,int n){
    int max = *p; //将数组的首元素的值赋给max
//    for(int i = 1;i < n;i++){
//        if(max < *(p + i)){
//            max = *(p + i);
//        }
//    }

    for(int i = 1;i < n;i++){
        if(max < p[i]){
            max = p[i];
        }
    }

    return max;
}

int main(){

    int arr[N];
    for(int i = 0;i < N;i++){
        scanf("%d",&arr[i]);
    }

    printf("max = %d\n", pMax(arr,N));

    return 0;
}