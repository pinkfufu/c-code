//
// Created by ZhangYao on 2026/5/8.
//
#include <stdio.h>
#include <string.h>

/**
 * 需求：键盘录入一个字符串，使用程序实现在控制台遍历该字符串
 * @return
 */

int main() {
    setbuf(stdout, NULL);
    int len;
    char str[100]; // 定义一个足够大的缓冲区

    printf("请输入设定的最大长度 len: ");
    scanf("%d", &len);

    // 使用 do-while 循环实现“不符合要求就重新输入”
    do {
        printf("请输入一个长度不超过 %d 的字符串: ", len);
        scanf("%s", str);

        // 判断实际输入的长度是否超过了设定值 len
        if (strlen(str) > len) {
            printf("错误：字符串太长了（当前长度 %zu），请重新输入！\n", strlen(str));
        } else {
            break; // 长度合格，跳出循环
        }
    } while (1);

    // 遍历输出
    printf("遍历结果为: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
