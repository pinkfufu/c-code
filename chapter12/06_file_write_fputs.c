//
// Created by ZhangYao on 2026/5/11.
//


#include <stdio.h>

/**
fputs：一次写一个字符串

fputs(str, fp) 把字符串写入文件，不会在末尾添加 '\0' 或换行符，字符串原样写入（遇到的 '\0' 不会写入，因为那是字符串结束标记）。
如果想要换行，需在字符串中显式加入 '\n'。
fputs 的返回值：成功时返回一个非负数（通常是写入的字符数），失败时返回 EOF。
 */
int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    const char *filename = "E:\\c-code\\chapter12\\fputs_output.txt";
    FILE *fp = fopen(filename, "w"); // 写模式
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    printf("=== 使用 fputs 逐行写入 ===\n");
    // fputs 不会自动添加换行，需要时自己加 '\n'
    fputs("第一行内容\n", fp);
    fputs("第二行内容\n", fp);
    fputs("第三行（不自动换行）", fp);
    fputs("，还是同一行\n", fp);

    printf("写入成功，请查看文件：%s\n", filename);
    fclose(fp);
    return 0;
}
