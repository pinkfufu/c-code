//
// Created by ZhangYao on 2026/4/22.
//
// 一维数组的定义

#include <stdio.h>

#define NUM 10

int main(){

    //1. 数组的定义
    int arr[10];
    int arr1[NUM];

    //2. 数组元素的调用：使用角标
    //角标的合法范围是：从0开始,到数组的长度-1结束
    arr[0] = 10;//给数组的第1个元素赋值
    arr[1] = 20;//给数组的第2个元素赋值
    //...

    //3. 问题：数组角标越界
    //只要角标不在合法范围内，都是越界。比如：-1,-2,数组的长度,数组的长度+1
    int arr2[5];
    arr2[5] = 10; //错误的！
    printf("%d\n",arr2[5]); //没有必要打印了

    //4. 关于长度
    //4.1 数组占用的字节数
    int arr3[20];
    printf("数组占用的字节数为：%zd\n",sizeof(arr3)); //80

    double arr4[5];
    printf("数组占用的字节数为：%zd\n",sizeof(arr4));//40

    //4.2 数组的长度
    printf("数组的长度为：%zd\n",sizeof(arr3) / sizeof(int)); //20
    printf("数组的长度为：%zd\n",sizeof(arr4) / sizeof(double)); //5

    //5. 一维数组的遍历
    //声明长度为10的int类型数组，给数组元素依次赋值为0,1,2,3,4,5,6,7,8,9，并遍历数组所有元素
    int nums[10];
    size_t length = sizeof(nums) / sizeof(int); //sizeof()返回的类型标准情况下是size_t
    //给每一个数组元素赋值
    for(int i = 0;i < length;i++){
        nums[i] = i;
    }
    //遍历数组元素
    printf("遍历一维数组的元素：\n");
    for(int i = 0;i < length;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");

/*
*其他补充：
- 数组中的元素在内存中是依次紧密排列的，有序的。
- 创建数组对象会在内存中开辟一整块`连续的空间`。占据的空间的大小，取决于数组的长度和数组中元素的类型。
- 我们可以直接通过下标(或索引)的方式调用指定位置的元素，速度很快。
- 数组，一旦初始化完成，其长度就是确定的。数组的`长度一旦确定，就不能修改`。
- 数组名中引用的是这块连续空间的首地址。
*/
        // 1. 初始化：长度确定为 5，类型为 int（通常占 4 字节）
        int scores[5] = {90, 85, 92, 78, 88};

        // 2. 数组名 scores 引用的是首地址
        printf("数组首地址 (scores): %p\n", scores);
        printf("第一个元素的地址 (&scores[0]): %p\n\n", &scores[0]);

        printf("元素下标 | 元素值 | 内存地址\n");
        printf("---------|--------|----------\n");

        for (int i = 0; i < 5; i++) {
            // 3. 打印每个元素的地址
            // %p 用于打印指针（地址），& 是取地址符
            printf("  [%d]    |   %d   | %p\n", i, scores[i], &scores[i]);
        }

        // 4. 计算数组占据的总空间
        printf("\n数组长度: 5");
        printf("\n每个 int 占据空间: %zu 字节", sizeof(int));
        printf("\n数组总占据空间: %zu 字节\n", sizeof(scores));

        return 0;
    }