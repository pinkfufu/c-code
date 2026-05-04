//
// Created by ZhangYao on 2026/5/5.
//
//高级指针

#include <stdio.h>

int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *P = &arr[0];
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(P + i));
    }

    return 0;
}
