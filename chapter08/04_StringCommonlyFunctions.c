//
// Created by ZhangYao on 2026/5/9.
//
#include <stdio.h>
#include <string.h>
/*
strlen：获取字符串的长度
strcat：拼接两个字符串
strcpy：复制字符串
strcmp：比较两个字符串
strlwr：将字符串变成小写
strupr：将字符串变成大写
*/
int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    // 准备测试用的字符串
    char str1[50] = "Hello";
    char str2[] = "World";
    char str3[50];

    // ==================== 1. strlen —— 获取字符串长度 ====================
    printf("=== strlen ===\n");
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    printf("str1: \"%s\", 长度 = %d\n", str1, len1);
    printf("str2: \"%s\", 长度 = %d\n", str2, len2);
    // 注意：长度不包括结尾的 '\0'

    // ==================== 2. strcat —— 拼接字符串 ====================
    printf("\n=== strcat ===\n");
    // 复制一份 str1 用于拼接，防止破坏原变量
    char buf[50] = "Hello";
    strcat(buf, " ");
    strcat(buf, str2);
    printf("拼接后: \"%s\"\n", buf);
    // 注意：目标数组必须有足够空间存放拼接后的结果

    // ==================== 3. strcpy —— 复制字符串 ====================
    printf("\n=== strcpy ===\n");
    strcpy(str3, str1); // 将 str1 复制到 str3
    printf("str3 (复制 str1 后): \"%s\"\n", str3);
    // 注意：目标数组必须足够大，防止溢出

    // ==================== 4. strcmp —— 比较字符串 ====================
    printf("\n=== strcmp ===\n");
    int cmp1 = strcmp("apple", "banana");
    int cmp2 = strcmp("apple", "apple");
    int cmp3 = strcmp("banana", "apple");
    printf("strcmp(\"apple\", \"banana\") = %d  (负数, 因为 'a' < 'b')\n", cmp1);
    printf("strcmp(\"apple\", \"apple\")  = %d  (相等)\n", cmp2);
    printf("strcmp(\"banana\", \"apple\") = %d  (正数, 因为 'b' > 'a')\n", cmp3);

    // ==================== 5. strlwr —— 转换为小写 ====================
    printf("\n=== strlwr (非标准, Windows 常见) ===\n");
    // 如果有 strlwr 函数（如 Windows 下）可以直接用：
    char lowerTest[] = "Hello World 123";
    printf("原字符串: \"%s\"\n", lowerTest);
#ifdef _WIN32
    strlwr(lowerTest); // 只在 Windows 下可用
    printf("strlwr 后: \"%s\"\n", lowerTest);
#else
    // 可移植的替代写法：手动转小写
    for (int i = 0; lowerTest[i]; i++)
        lowerTest[i] = tolower((unsigned char) lowerTest[i]);
    printf("手动转小写后: \"%s\"\n", lowerTest);
#endif


    // ==================== 6. strupr —— 转换为大写 ====================
    printf("\n=== strupr (非标准, Windows 常见) ===\n");
    char upperTest[] = "Hello World 123";
    printf("原字符串: \"%s\"\n", upperTest);
#ifdef _WIN32
    strupr(upperTest); // 只在 Windows 下可用
    printf("strupr 后: \"%s\"\n", upperTest);
#else
    for (int i = 0; upperTest[i]; i++)
        upperTest[i] = toupper((unsigned char) upperTest[i]);
    printf("手动转大写后: \"%s\"\n", upperTest);
#endif

    return 0;
}
