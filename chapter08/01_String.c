//
// Created by ZhangYao on 2026/5/8.
//


#include <stdio.h>

int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    // 字符串定义的两种方式：
    // 1.利用字符数组+双引|号的方式定义字符串 数组的长度要么不写，要么预留结束长度'\0'
    char str[13] = "Hello World!";
    printf("%s\n", str);
    // 2.字符串的内容是可以修改的
    str[0] = 'h'; // 修改字符串内容
    printf("%s\n", str);

    printf("--------------\n");

    // 3.利用字符指针+双引|号的方式定义字符串 字符串内容不可修改
    char *str2 = "Hello World!";
    printf("%s\n", str2);
    // str2[0] = 'h'; // 错误：修改字符串内容 会导致未定义行为
    str2[0] = 'h';
    printf("%s\n", str2);




    return 0;
}
