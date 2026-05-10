#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096   // 每次读取 4KB

int main() {
    // 解决 Windows 输出缓冲问题（可选）
    setbuf(stdout, NULL);

    // 源文件路径：桌面上的 mv.mp4
    // 根据实际用户名修改 "ZhangYao" 或动态获取（本示例直接写用户名，需按实际情况调整）
    const char *srcPath = "D:\\Users\\ZhangYao\\Desktop\\mv.mp4";

    // 目标路径：桌面上的 copy 文件夹内，文件名保持不变
    const char *destPath = "D:\\Users\\ZhangYao\\Desktop\\copy\\mv.mp4";

    FILE *srcFile = fopen(srcPath, "rb");   // 二进制只读
    if (srcFile == NULL) {
        perror("打开源文件失败");
        printf("请确认路径是否正确：%s\n", srcPath);
        return 1;
    }

    FILE *destFile = fopen(destPath, "wb"); // 二进制只写，覆盖或创建
    if (destFile == NULL) {
        perror("创建目标文件失败");
        printf("请确认目标目录是否存在：%s\n", destPath);
        fclose(srcFile);
        return 1;
    }

    // 动态分配缓冲区
    char *buffer = (char*)malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        perror("内存分配失败");
        fclose(srcFile);
        fclose(destFile);
        return 1;
    }

    size_t bytesRead;
    // 循环读取源文件并写入目标文件
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
        size_t bytesWritten = fwrite(buffer, 1, bytesRead, destFile);
        if (bytesWritten != bytesRead) {
            perror("写入数据出错");
            free(buffer);
            fclose(srcFile);
            fclose(destFile);
            return 1;
        }
    }

    // 检查读取是否因为错误而终止
    if (ferror(srcFile)) {
        perror("读取文件出错");
    } else {
        printf("文件拷贝成功！\n从：%s\n到：%s\n", srcPath, destPath);
    }

    // 清理工作
    free(buffer);
    fclose(srcFile);
    fclose(destFile);

    return 0;
}