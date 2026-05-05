//
// Created by ZhangYao on 2026/5/5.
//
#include <stdio.h>

void increment(int a) {
    a++;
    printf("a = %d\n",a); // a = 11
}

int increment1(int a) {
    a++;
    printf("a = %d\n",a); // a = 11
    return a;
}

int main(){
    int i = 10;
    printf("i = %d\n", i); // i = 10

//    increment(i);

    i = increment1(i);

    printf("i = %d\n", i); // i = 10  ---> i = 11
    return 0;
}
