//
// Created by ZhangYao on 2026/5/10.
//


#include <stdio.h>
#include <stdio.h>


int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);
    // r 读，w 写清空，a 追加写不清空；加 b 变二进制避免换行符转换；r 需要文件已存在，w/a 会自动创建。


    char fileAddress[] = "E:\\c-code\\chapter12\\File.txt";
    char buffer[200]; // 专门用来存放读取的内容
    FILE *file = fopen(fileAddress, "r");
    if (file == NULL) {
        printf("无法打开文件 %s\n", fileAddress);
        return 1;
    }
    // 读一行，放到 buffer 里，并检查是否成功
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("读到的内容：%s", buffer); // 打印出来
    } else {
        printf("文件为空或读取失败\n");
    }

    fclose(file);


    return 0;
}
