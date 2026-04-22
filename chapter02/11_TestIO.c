//
// Created by ZhangYao on 2026/4/22.
//


#include <stdio.h>

int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    printf("喵喵喵");

    return 0;
}
