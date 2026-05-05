//
// Created by ZhangYao on 2026/5/5.
//
#include <stdio.h>

int counter = 10;

void add(){
    counter++;
    printf("counter = %d\n",counter);
}

int main() {
    add();
    add();
    printf("counter = %d\n",counter); //counter = 12
    int counter = 0;
    printf("counter = %d\n",counter); //counter = 100
    return 0;
}