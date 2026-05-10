//
// Created by ZhangYao on 2026/5/11.
//


#include <stdio.h>

/**
*
fwrite：一次写多个字节（二进制安全）
*
fwrite(ptr, size, count, fp) 将 count 个大小为 size 字节的数据块写入文件。
返回实际写入的完整块数。
适合写入二进制数据（数组、结构体、图像的原始字节等）。
如果用 "w"（文本模式）写结构体，可能在 Windows 下因换行转换导致数据损坏，所以推荐用 "wb"（二进制写模式）来避免这个问题。
 */
int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    const char *filename = "E:\\c-code\\chapter12\\fwrite_output.txt";
    FILE *fp = fopen(filename, "wb");   // 二进制写模式，避免换行转换
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    printf("=== 使用 fwrite 写入数据 ===\n");
    // 示例1：写入一个整数数组
    int numbers[] = {100, 200, 300, 400, 500};
    size_t numElements = sizeof(numbers) / sizeof(numbers[0]);
    size_t writtenInts = fwrite(numbers, sizeof(int), numElements, fp);
    printf("写入 %zu 个整数（二进制）\n", writtenInts);

    return 0;
}