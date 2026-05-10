//
// Created by ZhangYao on 2026/5/10.
//

// 读取数据：fgetc一次读一个字符，读不到返回-1 fgets一次读一行，读不到返回null  fread一次读多个
#include <stdio.h>
#include <windows.h>

/**
fgets 读取一行，直到遇到换行、文件结束或缓冲区满（保留换行符）。
返回 NULL 表示读失败或已到文件末尾。
适合按行处理文本（日志分析、配置文件）。
 */
int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    const char *filename = "E:\\c-code\\chapter12\\File.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    printf("=== 使用 fgets 逐行读取 ===\n");
    char line[256]; // 缓冲区，存放一行
    int lineNum = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("第%d行: %s", ++lineNum, line); // line 中已包含换行符
        Sleep(500);
    }
    fclose(fp);

    return 0;
}
