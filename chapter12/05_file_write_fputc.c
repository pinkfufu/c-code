//
// Created by ZhangYao on 2026/5/11.
//


#include <stdio.h>
/**
// fputc：一次写一个字符
fputc(ch, fp) 写一个字符到文件。
适合需要逐字符输出或转换的场景。
 */
int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    const char *filename = "E:\\c-code\\chapter12\\fputc_output.txt";
    FILE *fp = fopen(filename, "w"); // 只写，文件存在则清空，不存在则创建
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    printf("=== 使用 fputc 逐字符写入 ===\n");
    const char *text = "Hello, fputc!\nLine 2";
    for (int i = 0; text[i] != '\0'; i++) {
        if (fputc(text[i], fp) == EOF) {
            // fputc 返回写入的字符，失败返回 EOF
            perror("fputc");
            fclose(fp);
            return 1;
        }
    }
    printf("写入成功，请查看文件：%s\n", filename);
    fclose(fp);


    return 0;
}
