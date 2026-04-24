//
// Created by ZhangYao on 2026/4/24.
//
// 指针可以令函数的结果和计算状态分散开


#include <stdio.h>

// 修正点1：增加 length 参数，因为数组在函数中会退化为指针
void getArrMaxAndMin(int arr[], int length, int *max, int *min);

int getRemainder(int num1, int num2, int *res);

int main() {
    setbuf(stdout, NULL);

    int arr[] = {12, 5, 33, 4, 98, 6, 71, 8, 2};
    // 在 main 中计算长度是准确的
    int length = sizeof(arr) / sizeof(arr[0]);
    int max, min; // 这里不需要初始化，函数内部会处理
    getArrMaxAndMin(arr, length, &max, &min);
    printf("max = %d, min = %d\n", max, min);

    int res;
    if (!getRemainder(10, 3, &res)) printf("Remainder = %d\n", res);
    return 0;
}

// 取一个数组中的最大值和最小值
void getArrMaxAndMin(int arr[], int length, int *max, int *min) {
    // 先假设第一个元素就是最大和最小值
    *max = arr[0];
    *min = arr[0];

    // 只需要一个循环，走一遍数组即可
    for (int i = 1; i < length; i++) {
        // 查找最大值
        if (arr[i] > *max) {
            *max = arr[i]; // 发现更大的，把 arr[i] 存入 max 指向的地址
        }
        // 查找最小值
        if (arr[i] < *min) {
            *min = arr[i]; // 发现更小的，把 arr[i] 存入 min 指向的地址
        }
    }
}

/**
 * 获取余数
 * 返回值：0 表示计算成功，-1 表示除数为 0（计算失败）
 */
int getRemainder(int num1, int num2, int *res) {
    // 1. 安全检查：防范除 0 错误
    if (num2 == 0) {
        return -1; // 告知外部：出错了！
    }
    // 2. 执行计算：通过指针“远程操控”修改结果
    *res = num1 % num2;
    return 0; // 告知外部：成功了！
}
