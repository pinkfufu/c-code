//
// Created by ZhangYao on 2026/5/9.
//


#include <stdio.h>

int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);
    // 定义一个数组存储5个学生的名字并进行遍历
    char strArr[5][100] = {
        "zhangsan",
        "lisi",
        "wangwu",
        "zhaoliu",
        "tianqi"
    };

    // 遍历数组并输出每个学生的名字
    for (int i = 0; i < 5; ++i) {
        char *string = strArr[i];
        printf("%s\n", string);
    }

    printf("================================================\n");

    const char *strArr2[5] = {
        // 指针数组，每个元素是一个字符串常量
        "zhangsan",
        "lisi",
        "wangwu",
        "zhaoliu",
        "tianqi"
    };

    for (int i = 0; i < 5; i++) {
        const char *str = strArr2[i];
        printf("%s\n", str); // 直接打印整个字符串
    }

    return 0;
}
