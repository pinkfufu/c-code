#include <stdio.h>
#include <string.h>

// 定义共用体：成员包括 int、double、字符串
union Data {
    int i;
    double d;
    char str[20];
};

int main() {
    setbuf(stdout, NULL);

    union Data data;

    // 1. 查看共用体总大小
    printf("=== 特性：大小 = 最大成员的长度（受内存对齐影响）===\n");
    printf("int 大小: %zu\n", sizeof(int));
    printf("double 大小: %zu\n", sizeof(double));
    printf("char[20] 大小: %zu\n", sizeof(char[20]));
    printf("union Data 大小: %zu\n\n", sizeof(data));
    // 因为 double 通常是 8 字节，char[20] 是 20 字节，所以总大小至少 20 字节，
    // 但可能因对齐填充到 24 字节（不同平台可能不同）

    // 2. 演示“每次只能给一个变量赋值，第二次赋值会覆盖原有数据”
    printf("=== 特性：覆盖赋值 ===\n");

    // 赋值整数
    data.i = 100;
    printf("赋值 data.i = 100 后:\n");
    printf("  data.i = %d\n", data.i);
    printf("  data.d = %f (已无意义)\n", data.d);
    printf("  data.str = %s (乱码，无意义)\n\n", data.str);

    // 赋值浮点数（覆盖掉整数的内存）
    data.d = 3.14;
    printf("赋值 data.d = 3.14 后:\n");
    printf("  data.d = %f\n", data.d);
    printf("  data.i = %d (已无意义，可能乱码)\n", data.i);
    printf("  data.str = %s (乱码)\n\n", data.str);

    // 赋值字符串（覆盖掉浮点数的内存）
    strcpy(data.str, "Hello");
    printf("赋值 data.str = \"Hello\" 后:\n");
    printf("  data.str = %s\n", data.str);
    printf("  data.i = %d (已无意义)\n", data.i);
    printf("  data.d = %f (已无意义)\n\n", data.d);

    // 3. 共用体的典型应用：同一份数据的不同表现形式
    // 例如判断一个浮点数是否为正数，可以用整数位运算
    data.d = -5.5;
    if (data.i < 0) {
        printf("应用：通过共用体用整数方式判断浮点数符号位：%.2f 是负数\n", data.d);
    }

    return 0;
}