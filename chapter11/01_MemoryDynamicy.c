//
// Created by ZhangYao on 2026/5/10.
//


#include <stdio.h>
#include <stdlib.h>  // malloc, calloc, realloc, free 需要
#include <string.h>  // memcpy 用于展示

int main() {
    setbuf(stdout, NULL);

    // ================= 1. malloc：申请空间（不初始化） =================
    printf("=== malloc ===\n");
    int n = 5;
    // 申请 5 个 int 的空间，内容为随机值
    int *arr_malloc = (int *) malloc(n * sizeof(int));
    if (arr_malloc == NULL) {
        printf("malloc 失败\n");
        return 1;
    }
    printf("malloc 申请 %d 个 int 空间，初始值（未初始化，是随机值）：\n", n);
    for (int i = 0; i < n; i++) {
        printf("  arr_malloc[%d] = %d\n", i, arr_malloc[i]);
    }

    // ================= 2. calloc：申请空间 + 初始化为 0 =================
    printf("\n=== calloc ===\n");
    // 申请 5 个 int 的空间，自动清零
    int *arr_calloc = (int *) calloc(n, sizeof(int));
    if (arr_calloc == NULL) {
        printf("calloc 失败\n");
        free(arr_malloc);
        return 1;
    }
    printf("calloc 申请 %d 个 int 空间，初始值（自动清零）：\n", n);
    for (int i = 0; i < n; i++) {
        printf("  arr_calloc[%d] = %d\n", i, arr_calloc[i]);
    }

    // 给 malloc 的数组手动赋值，演示初始化过程
    for (int i = 0; i < n; i++) {
        arr_malloc[i] = (i + 1) * 10; // 10, 20, 30, 40, 50
    }
    printf("手动初始化 malloc 数组后: ");
    for (int i = 0; i < n; i++) printf("%d ", arr_malloc[i]);
    printf("\n");

    // ================= 3. realloc：修改已分配空间的大小 =================
    printf("\n=== realloc：扩容从 %d 到 %d ===\n", n, n * 2);
    int new_n = n * 2;
    // 尝试将 arr_malloc 扩容到 10 个 int
    int *arr_realloc = (int *) realloc(arr_malloc, new_n * sizeof(int));
    if (arr_realloc == NULL) {
        printf("realloc 失败，原空间仍保留\n");
        free(arr_malloc);
    } else {
        arr_malloc = arr_realloc; // 指针更新为可能的新地址
        printf("realloc 成功，新空间大小 %d 个 int\n", new_n);
        // 原有数据被保留，新扩展部分未初始化
        printf("原有数据: ");
        for (int i = 0; i < n; i++) printf("%d ", arr_malloc[i]);
        printf("\n新扩展部分（随机值）: ");
        for (int i = n; i < new_n; i++) printf("%d ", arr_malloc[i]);
        printf("\n");
    }

    // 给新扩展部分赋值
    for (int i = n; i < new_n; i++) {
        arr_malloc[i] = (i + 1) * 10;
    }
    printf("填充新空间后: ");
    for (int i = 0; i < new_n; i++) printf("%d ", arr_malloc[i]);
    printf("\n");

    // 也可以用 realloc 缩小空间
    printf("\n=== realloc：缩小从 %d 到 %d ===\n", new_n, 3);
    int *shrunk = (int *) realloc(arr_malloc, 3 * sizeof(int));
    if (shrunk != NULL) {
        arr_malloc = shrunk;
        printf("缩小成功，现在只有 3 个元素: ");
        for (int i = 0; i < 3; i++) printf("%d ", arr_malloc[i]);
        printf("\n");
    }

    // ================= 4. free：释放动态内存 =================
    printf("\n=== free：释放所有动态内存 ===\n");
    free(arr_malloc); // 释放 malloc/realloc 的空间
    free(arr_calloc); // 释放 calloc 的空间
    arr_malloc = NULL; // 好习惯，避免野指针
    arr_calloc = NULL;

    printf("内存已释放，程序结束。\n");
    return 0;
}
