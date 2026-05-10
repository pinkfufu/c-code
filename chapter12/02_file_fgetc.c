//
// Created by ZhangYao on 2026/5/10.
//

#include <windows.h>  // Windows 下需要
#include <stdio.h>
// 读取数据：fgetc一次读一个字符，读不到返回-1 fgets一次读一行，读不到返回null  fread一次读多个
int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    const char *filename = "E:\\c-code\\chapter12\\File.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    printf("=== 使用 fgetc 逐字符读取 ===\n");
    int ch;
    while ((ch = fgetc(fp)) != EOF) {   // fgetc 返回 int，读到末尾返回 EOF
        putchar(ch);                     // 输出到屏幕
        Sleep(50);
    }

    fclose(fp);

    return 0;
}
