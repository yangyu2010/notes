#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // int array_datas[] = {6, 2, 1, 10, 21, 19, 5, 12, 9};
    // int array_datas[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    // int array_datas[] = {4, 6, 6, 6, 8, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71,
    // 99};
    // int array_datas[] = {13, 13, 20, 76, 22, 56, 78, 26, 91, 59, 33, 62,
    //                      63, 93, 68, 39, 65, 86, 41, 88, 20, 91, 93};
    // int array_datas[] = {13, 76, 22, 56, 78, 26};

    // int array_datas[] = {6, 6, 6, 6, 6, 6, 6};
    // int array_datas[] = {7, 1, 2, 3, 4, 5, 6};

    int array_datas[] = {
        80, 82, 50, 11, 100, 30, 36, 71, 43, 94, 55, 21, 59, 3,  37, 24, 89,
        81, 90, 18, 52, 27,  42, 21, 54, 57, 2,  41, 29, 65, 96, 90, 24, 9,
        96, 22, 35, 70, 12,  39, 68, 1,  81, 36, 89, 88, 77, 16, 29, 8,  66,
        46, 71, 64, 63, 43,  55, 73, 92, 96, 44, 4,  98, 31, 81, 24, 78};

    int arraySize = sizeof(array_datas);
    int intSize = sizeof(array_datas[0]);
    int length = arraySize / intSize;

    int *array = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        array[i] = array_datas[i];
    }

    printf("\n排序之前的数组\n");
    for (int i = 0; i < length; i++) {
        printf("%d,", array[i]);
    }
    printf("\n排序之前的数组\n\n");

    // 1.找最大值
    int max = array[0];
    for (int i = 0; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    // printf("%d,", max);

    // 2.创建 Count Array
    // 里面存储的是每个元素出现的次数
    int *countArray = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < length; i++) {
        int item = array[i];
        countArray[item] += 1;
    }

    for (int i = 0; i < max + 1; i++) {
        printf("%d,", countArray[i]);
    }

    // 3.遍历 Count Array
    // 如果存储的值大于0 代表这个下标有值
    int index = 0;
    for (int i = 0; i < max + 1; i++) {
        // int count = countArray[i];
        // while (count > 0) {
        //     array[index] = i;
        //     index++;
        //     count--;
        // }

        while (countArray[i]--) {
            array[index++] = i;
        }
    }

    printf("\n排序之后的数组\n");
    int prev = array[0];
    printf("%d,", array[0]);
    for (int i = 1; i < length; i++) {
        printf("%d,", array[i]);
        if (array[i] < prev) {
            printf("\n========not ascending order=============\n");
            break;
        }
        prev = array[i];
    }
    printf("\n排序之后的数组\n\n");

    return 0;
}