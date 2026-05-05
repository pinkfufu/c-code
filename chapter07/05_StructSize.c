#include <stdio.h>
//
// Created by ZhangYao on 2026/5/5.
//
// 测试结构体占用的空间


struct A{
    char a;
    int b;
    char c;
} s;

int main() {
    printf("%d\n", sizeof(s)); // 12
    return 0;
}