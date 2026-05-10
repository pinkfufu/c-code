//
// Created by ZhangYao on 2026/5/10.
//

#include <stdio.h>
#include <stdlib.h>

/**
fread(void *ptr, size_t size, size_t nmemb, FILE *stream) 按块读取。
返回实际读取的块数（nmemb 的值），如果小于请求数可能是遇到 EOF 或错误。
适合读取二进制数据（如图片、音频）或已知大小的文件，效率高。
这里用二进制模式 "rb" 确保字节数准确。
 */

/**
 *Buffer        void*   内存缓冲区的地址，从文件中读到的数据就存到这里。这块内存必须由你自己事先分配好。
 *ElementSize   size_t  每个元素的大小，单位是字节。比如读取 int 数组时，ElementSize = sizeof(int)（通常为4）。
 *ElementCount	size_t	要读取的元素个数，不是总字节数。总读取字节数 = ElementSize × ElementCount。
 *Stream	    FILE*	文件指针，由 fopen 返回的已打开文件的句柄。
 */
int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    const char *filename = "E:\\c-code\\chapter12\\File.txt";
    FILE *fp = fopen(filename, "rb"); // 用二进制模式，避免换行转换干扰
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    // 获取文件大小
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp); // 回到开头

    // 分配内存存放整个文件内容
    char *buffer = (char *) malloc(fileSize + 1);
    if (buffer == NULL) {
        perror("malloc");
        fclose(fp);
        return 1;
    }

    // 一次性读取 fileSize 个字节（1 个块，块大小 = fileSize）
    size_t bytesRead = fread(buffer, 1, fileSize, fp);
    if (bytesRead != fileSize) {
        perror("fread");
        free(buffer);
        fclose(fp);
        return 1;
    }
    buffer[fileSize] = '\0'; // 方便当字符串处理

    printf("=== 使用 fread 一次读取 %ld 字节 ===\n", fileSize);
    printf("%s\n", buffer);

    free(buffer);
    fclose(fp);

    return 0;
}
