//
// Created by ZhangYao on 2026/5/9.
//


#include <stdio.h>
#include <string.h>
/*
需求：已知正确的用户名和密码，请用程序实现模拟用户登录。
总共给三次机会，登录之后，给出相应的提示
*/
int main() {
    // 解决 Windows 下控制台输出缓冲区导致的显示延迟问题
    setbuf(stdout, NULL);

    char username[20];
    char password[20];
    const char correctUsername[] = "admin";
    const char correctPassword[] = "123456";

    for (int i = 0; i < 3; i++) {
        // 用户输入
        printf("第%d次登录尝试：", i + 1);
        printf("请输入用户名username：");
        scanf("%s", username);
        printf("请输入密码password：");
        scanf("%s", password);

        // 比较用户名和密码三次
        // 对比成功 登录，否则 登录失败
        if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
            printf("登录成功！\n");
            break; // 登录成功，退出循环
        } else {
            printf("登录失败！\n");
        }
    }

    return 0;
}
