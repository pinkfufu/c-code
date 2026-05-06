//
// Created by ZhangYao on 2026/5/6.
//

//结构体嵌套
#include <stdio.h>
#include <string.h>

struct Name {
    char firstName[50];
    char lastName[50];
};

struct Student {
    int age;
    struct Name name;
    char gender;
} stu1;

int main(){
    strcpy(stu1.name.firstName, "美美");
    strcpy(stu1.name.lastName, "韩");
    //stu1.age = 18;
    //stu1.gender = 'F';

    //或者
    struct Name myname = {"美美","韩"};
    stu1.name = myname;
    //stu1.age = 18;
    //stu1.gender = 'F';

    printf("firstName = %s ,lastName = %s\n", stu1.name.firstName, stu1.name.lastName);
    return 0;
}