#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void sort(int *, int, int);

/*
The sorting used 5.341000 ms by clock()
The sorting used 0.000000 s by time() 
 */
int main() {
    // int array_datas[] = {6, 2, 1, 10, 21, 19, 5, 12, 9};
    // int array_datas[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    // int array_datas[] = {4, 6, 6, 6, 8, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71,
    // 99}; int array_datas[] = {13, 13, 20, 76, 22, 56, 78, 26, 91, 59, 33, 62,
    //                      63, 93, 68, 39, 65, 86, 41, 88, 20, 91, 93};
    // int array_datas[] = {13, 76, 22, 56, 78, 26};

    // int array_datas[] = {6, 6, 6, 6, 6, 6, 6};
    // int array_datas[] = {7, 1, 2, 3, 4, 5, 6};

    // int array_datas[] = {
    //     80, 82, 50, 11, 100, 30, 36, 71, 43, 94, 55, 21, 59, 3,  37, 24, 89,
    //     81, 90, 18, 52, 27,  42, 21, 54, 57, 2,  41, 29, 65, 96, 90, 24, 9,
    //     96, 22, 35, 70, 12,  39, 68, 1,  81, 36, 89, 88, 77, 16, 29, 8,  66,
    //     46, 71, 64, 63, 43,  55, 73, 92, 96, 44, 4,  98, 31, 81, 24, 78};

    // int arraySize = sizeof(array_datas);
    // int intSize = sizeof(array_datas[0]);
    // int length = arraySize / intSize;

    // int *array = (int *)calloc(length, sizeof(int));
    // for (int i = 0; i < length; i++) {
    //     array[i] = array_datas[i];
    // }

    int length = 100000;
    int *array = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        array[i] = random() % 10000;
    }
    for (int i = 0; i < length; i++) {
        printf("%d,", array[i]);
    }

    time_t c_start, t_start, c_end, t_end;
    c_start = clock();    //!< 单位为ms
    t_start = time(NULL); //!< 单位为s

    //================上面是准备数据代码 下面才是真正排序的代码================
    int max = array[0];
    for (int i = 0; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    for (int i = 1; i <= max; i *= 10) {
        // 1
        // 10
        // 100
        // 1000
        sort(array, length, i);
    }

    //======下面是估算排序时间和验证排序的准确性,上面才是真正排序的代码=========

    c_end = clock();
    t_end = time(NULL);
    printf("\n\nThe sorting used %f ms by clock()\n",
           difftime(c_end, c_start) / CLOCKS_PER_SEC * 1000);
    printf("The sorting used %f s by time()\n", difftime(t_end, t_start));

    int prev = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < prev) {
            printf("\n========👎👎👎👎 not ascending order=============\n");
            break;
        }
        prev = array[i];
    }
    printf("\n========yes 👍👍👍👍👍 ascending order=============\n");

    free(array);
    return 0;
}

/**
 * @brief 对数组进行基数排序 哪一位进行计数排序
 *
 * @param array 待排序的数组
 * @param length 数组长度
 * @param divider 对哪一位进行计数排序 1个位 10十位 100百位等
 */
void sort(int *array, int length, int divider) {
    int countSize = 10;
    // 2.创建 Count Array
    // 里面存储的是每个元素出现的次数
    int *countArray = (int *)calloc(countSize, sizeof(int));
    for (int i = 0; i < length; i++) {
        int item = array[i] / divider % 10;
        countArray[item] += 1;
    }
    for (int i = 1; i < countSize; i++) {
        countArray[i] += countArray[i - 1];
    }

    int *newArray = (int *)calloc(length, sizeof(int));
    for (int i = length - 1; i >= 0; i--) {
        int index = --countArray[(array[i] / divider % 10)];
        newArray[index] = array[i];
    }

    for (int i = 0; i < length; i++) {
        array[i] = newArray[i];
    }
}