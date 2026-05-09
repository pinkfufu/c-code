//
// Created by ZhangYao on 2026/5/9.
//


#include <stdio.h>
#include <string.h>

// 1. 先定义联系方式结构体（内部数据的结构）
struct Message {
    char phone[20];
    char email[50];
};

// 2. 再定义学生结构体，嵌套联系方式
struct Student {
    char name[50];
    int age;
    char gender; // 'M' 或 'F'
    double height;
    struct Message msg; // 嵌套的结构体变量，名字叫 msg
};

/**
定义一个结构体表示学生StudentStudent成员如下:
名字、年龄、性别、身高、联系方式
联系方式Message也是一个结构体，成员如下：手机号、电子邮箱
 */
int main() {
    setbuf(stdout, NULL);

    // 3. 初始化：嵌套部分用额外的大括号
    struct Message msg1 = {"13800138000", "zhangsan@abc.com"};
    struct Student stu1 = {
        "张三", 22, 'M', 178.5,
        msg1 // 直接使用之前定义的结构体变量
    };


    // 4. 访问和打印
    printf("姓名：%s\n", stu1.name);
    printf("手机：%s\n", stu1.msg.phone); // 多层"."访问
    printf("邮箱：%s\n", stu1.msg.email);

    // 5. 也可以逐个赋值修改
    struct Student stu2;
    strcpy(stu2.name, "李四");
    stu2.age = 21;
    // ... 其他赋值
    strcpy(stu2.msg.phone, "13900139000"); // 修改嵌套部分的数据
    printf("\n李四的手机：%s\n", stu2.msg.phone);

    return 0;
}
