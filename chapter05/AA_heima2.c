//
// Created by ZhangYao on 2026/5/3.
//


#include <stdio.h>

// 声明加减乘除四个函数
int add(int num1, int num2);

int sub(int num1, int num2);

int mul(int num1, int num2);

int div(int num1, int num2);

int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题

    setbuf(stdout, NULL);

    // --- 第一部分：直接调用 ---
    printf("直接调用结果：\n");
    printf("add = %d\n", add(10, 2));
    printf("sub = %d\n", sub(10, 2));

    // --- 第二部分：通过指针调用 ---
    printf("\n通过指针调用结果：\n");

    // 1. 定义并赋值
    int (*p)(int, int);

    // 2. 指向加法并调用
    p = add;
    printf("pAdd = %d\n", p(10, 2)); // 像使用普通函数一样使用指针名

    // 3. 指向减法并调用
    p = sub;
    printf("pSub = %d\n", p(12, 2));

    // 4. 指向乘法并调用
    p = mul;
    printf("pMul = %d\n", p(14, 2));

    // 5. 指向除法并调用
    p = div;
    printf("pDiv = %d\n", p(16, 2));

    return 0;
}

// 定义四个函数，实现两个数的加减整除
int add(int num1, int num2) {
    return num1 + num2;
}

int sub(int num1, int num2) {
    return num1 - num2;
}

int mul(int num1, int num2) {
    return num1 * num2;
}

int div(int num1, int num2) {
    return num1 / num2;
}
