//
// Created by ZhangYao on 2026/5/9.
//

#include <stdio.h>

// 使用 typedef 简化：以后用 R 代替 struct Role
typedef struct Role {
    char name[50];
    int attack; // 攻击力
    int defense; // 防御力
    int hp; // 血量
} R;

int main() {
    setbuf(stdout, NULL); // 解决 Windows 输出缓冲延迟

    // 把 3 个游戏人物放入数组，声明时直接初始化
    const R r1 = {"战士", 100, 80, 1200};
    const R r2 = {"法师", 150, 40, 800};
    const R r3 = {"刺客", 120, 50, 900};
    R heroes[3] = {r1, r2, r3};

    // 遍历数组，输出每个角色的信息
    printf("=== 游戏人物列表 ===\n");
    for (int i = 0; i < 3; i++) {
        printf("角色 %d: %s, 攻击:%d, 防御:%d, 血量:%d\n",
               i + 1,
               heroes[i].name,
               heroes[i].attack,
               heroes[i].defense,
               heroes[i].hp);
    }

    return 0;
}
