//
// Created by ZhangYao on 2026/5/5.
//
#include <stdio.h>


//声明一个结构体
struct Person {
    char name[20];
    int age;
};

int main() {

    struct Person per1 = {.name="Tom", .age = 12};
    //声明结构体指针
    struct Person *per_ptr = &per1;

    printf("%s\n",(*per_ptr).name);
    (*per_ptr).age = 20;
    printf("%d\n",(*per_ptr).age);


    return 0;
}
