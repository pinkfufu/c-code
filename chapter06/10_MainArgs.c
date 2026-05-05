//
// Created by ZhangYao on 2026/5/5.
//
#include <stdio.h>

int main(int argc, char *argv[]) {
    //函数体
    printf("argc = %d\n",argc);

    for(int i = 0;i < argc;i++){
        printf("%s\n",argv[i]);
    }

    return 0;
}