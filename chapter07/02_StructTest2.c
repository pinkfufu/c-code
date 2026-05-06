//
// Created by ZhangYao on 2026/5/6.
//


#include <stdio.h>

struct Cat {
    char *name;
    int age;
    char *gender;
};

int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    struct Cat cat = {
        .name = "Tom",
        .age = 12,
        .gender = "M"
    };
    printf("name = %s, age = %d, gender = %s\n", cat.name, cat.age, cat.gender);

    struct Cat cat1 = {"小黄", 3, "F"};
    printf("name = %s, age = %d, gender = %s\n", cat1.name, cat1.age, cat1.gender);



    return 0;
}
