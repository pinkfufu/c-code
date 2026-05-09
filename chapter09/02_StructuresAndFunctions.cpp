//
// Created by ZhangYao on 2026/5/9.
//

#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int age;
} S;

void method(S st);
void method(S *st);   // 参数改为指针

/**
* 结构体作为函数参数函数中可以传递结构体
两种情况：
传递结构体中的数据值
传递结构体的地址值
 */
int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    // 定义一个学生
    S s;

    // 给学生赋值
    strcpy(s.name, "张三");
    s.age = 18;

    // 打印
    printf("学生的姓名：%s \n学生的年龄：%d\n", s.name, s.age);

    // 调用函数
    // 数值传递修改
    method(s);
    printf("修改后--->学生的姓名：%s \n学生的年龄：%d\n", s.name, s.age);

    // 地址传递修改
    method(&s);       // 传递 s 的地址
    printf("修改后--->学生的姓名：%s\n学生的年龄：%d\n", s.name, s.age);
    return 0;
}

void method(S st) {
    printf("接收到main函数中学生的初始数据为：%s %d\n", st.name, st.age);

    // 修改学生的姓名和年龄
    printf("请输入要修改的学生名字: ");
    scanf("%s", st.name);
    printf("请输入要修改的学生年龄: ");
    scanf("%d", &st.age);

    printf("修改后的数据为：%s %d\n", st.name, st.age);
}
void method(S *st) {
    printf("接收到main函数中学生的初始数据为：%s %d\n", st->name, st->age);

    printf("请输入要修改的学生名字: ");
    scanf("%s", st->name);        // 用 -> 访问成员
    printf("请输入要修改的学生年龄: ");
    scanf("%d", &st->age);

    printf("修改后的数据为：%s %d\n", st->name, st->age);
}
