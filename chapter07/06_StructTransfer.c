//
// Created by ZhangYao on 2026/5/5.
//
#include <stdio.h>

struct Car {
    double price;
    char name[30];
} a = {.name = "Audi A6L", .price = 390000.99};

int main() {
    struct Car b = a;

    printf("%p\n", &a); //00007ff650969020
    printf("%p\n", &b); //00000026a29ffd70

    printf("%p\n", a.name); //00007ff650969020
    printf("%p\n", b.name); //00000026a29ffd70

    b.name[0] = 'B';
    printf("%s\n", b.name); //Budi A6L
    printf("%s\n", a.name); //Audi A6L

    return 0;
}
