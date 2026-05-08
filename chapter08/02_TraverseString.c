//
// Created by ZhangYao on 2026/5/8.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // 必须包含，用于 malloc 和 free

/**
 * 需求：键盘录入一个字符串，使用程序实现在控制台遍历该字符串
 * @return
 */

int main() {
    setbuf(stdout, NULL);
    int len;
    printf("请输入允许的最大字符串长度 (len): ");
    scanf("%d", &len);

    // 1. 根据输入的 len 动态分配内存
    // +1 是为了给字符串结束符 '\0' 预留空间
    char *str = (char *) malloc((len + 1) * sizeof(char));

    if (str == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    // 2. 循环录入并校验
    while (1) {
        printf("请输入字符串 (长度不能超过 %d): ", len);
        scanf("%s", str);

        // 获取实际录入的字符串长度 n
        int n = strlen(str);

        if (n > len) {
            printf("错误：你输入的长度为 %d，超过了限制 %d，请重新输入！\n", n, len);
            // 清理缓冲区（防止干扰下次输入）
            while (getchar() != '\n');
        } else {
            printf("输入成功！\n");
            break;
        }
    }

    // 3. 遍历输出
    printf("遍历结果为: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    // 4. 关键：手动释放动态内存
    free(str);

    return 0;
}
