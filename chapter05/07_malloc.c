#include <stdio.h>
#include <stdlib.h>

int main() {
    setbuf(stdout, NULL);

    int rows, cols;
    printf("请输入行数 (rows): ");
    scanf("%d", &rows);
    printf("请输入列数 (cols): ");
    scanf("%d", &cols);

    // 1. 申请第一维：存放指针的数组（每一行一个指针）
    int **array = (int **)malloc(sizeof(int *) * rows);
    if (array == NULL) return 1; // 内存分配失败处理

    // 2. 申请第二维：每一行具体的空间
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(sizeof(int) * cols);
        if (array[i] == NULL) return 1;

        for (int j = 0; j < cols; j++) {
            array[i][j] = 1;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // --- 重点：防泄漏释放过程 ---

    // 3. 先释放内部：把每一行的小盒子拆掉
    for (int i = 0; i < rows; i++) {
        free(array[i]); 
        array[i] = NULL; // 养成好习惯：释放后置空，防止野指针
    }

    // 4. 再释放外部：把存放指针的大盒子拆掉
    free(array);
    array = NULL;

    printf("\n内存已成功释放！\n");

    return 0;
}