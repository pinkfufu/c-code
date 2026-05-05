//
// Created by ZhangYao on 2026/5/5.
//
#include <stdio.h>

int m = 10,n = 20; //全局变量

void func1(int i){
    int j = 10;

    printf("m = %d\n",m);
}

void func2(){
    int i = 10;
    //代码块
    {
        int j = 20;
        printf("j = %d\n",j);
    }

//    printf("j = %d\n",j); //报错
    printf("i = %d\n",i);

    int m = 100; //局部变量
    printf("m = %d\n",m);
}

int main(){

    func2();

    return 0;
}
