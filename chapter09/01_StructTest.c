//
// Created by ZhangYao on 2026/5/9.
//
#include <stdio.h>
#include <string.h>

struct GirlFriend {
    char name[50];
    int age;
    char gender; // 'M' 或 'F' 等
    double height;
};

int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    struct GirlFriend gf;

    // 赋值
    // 方法一：声明时初始化（按顺序给值）
    struct GirlFriend gf1 = {"XiaoMei", 22, 'F', 165.5};
    // 打印验证
    printf("名字: %s\n", gf1.name);
    printf("年龄: %d\n", gf1.age);
    printf("性别: %c\n", gf1.gender);
    printf("身高: %.1f cm\n", gf1.height);

    // 方法二：先声明，再逐个字段赋值
    struct GirlFriend gf2;
    strcpy(gf2.name, "XiaoHong"); // 字符数组不能直接赋值，要用 strcpy
    gf2.age = 23;
    gf2.gender = 'F';
    gf2.height = 170.2;
    printf("\n--- gf2 ---\n");
    printf("名字: %s, 年龄: %d, 性别: %c, 身高: %.1f cm\n", gf2.name, gf2.age, gf2.gender, gf2.height);

    // 方法三：从键盘输入赋值
    struct GirlFriend gf3;
    printf("\n请输入女朋友的名字: ");
    scanf("%s", gf3.name); // %s 会自动放入数组，注意不要超过长度
    printf("请输入年龄: ");
    scanf("%d", &gf3.age);
    printf("请输入性别 (一个字母): ");
    scanf(" %c", &gf3.gender); // 注意 %c 前加空格，过滤回车
    printf("请输入身高 (cm): ");
    scanf("%lf", &gf3.height);

    printf("\n你输入的女朋友: %s, %d 岁, 身高 %.1f cm\n", gf3.name, gf3.age, gf3.height);


    return 0;
}
