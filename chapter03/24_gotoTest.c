//
// Created by ZhangYao on 2026/4/22.
//


#include <stdio.h>

int main() {
    setbuf(stdout, NULL);
    int score, i = 0, sum = 0;
nextStu:
    printf("请输入第 %d 个学生成绩(输入-1结束)：", i + 1);
    scanf("%d", &score);
    if (score != -1) {
        sum += score;
        i++;
        goto nextStu;
    }
    if (i != 0)
        printf("%d个学生的平均分是 %d\n", i, sum / i);

    return 0;
}
