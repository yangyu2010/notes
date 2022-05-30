// #include <>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

/**
The sorting used 22920.055000 ms by clock()
The sorting used 23.000000 s by time()
*/
// 记录下最后一次交换的位置
int main() {
    // int array[] = {1, 4, 6, 0, 71, 12, 9, 8, 26, 37, 44, 54};
    // int array[] = {0, 1, 4, 6, 8, 9, 12, 26, 37, 44, 54, 71};
    // int array[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    // int arraySize = sizeof(array);
    // int intSize = sizeof(array[0]);
    // int length = arraySize / intSize;

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
    for (int i = length; i > 0; i--) {
        int sortedIndex = 0;
        for (int j = 1; j < i; j++) {
            if (array[j - 1] > array[j]) {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;

                sortedIndex = j + 1;
            }
        }
        i = sortedIndex;
    }
    //======下面是估算排序时间和验证排序的准确性,上面才是真正排序的代码=========

    c_end = clock();
    t_end = time(NULL);
    printf("\nThe sorting used %f ms by clock()\n",
           difftime(c_end, c_start) / CLOCKS_PER_SEC * 1000);
    printf("The sorting used %f s by time()\n", difftime(t_end, t_start));

    int prev = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < prev) {
            printf("\n========👎👎👎👎 not ascending order=============\n");
            return 0;
        }
        prev = array[i];
    }
    printf("\n========yes 👍👍👍👍👍 ascending order=============\n");

    free(array);

    return 0;
}

/**
The sorting used 22506.400000 ms by clock()
The sorting used 23.000000 s by time()
 */
// 冒泡排序(有序后提前退出)
int main1() {

    // int array[] = {1, 4, 6, 0, 71, 12, 9, 8, 26, 37, 44, 54};
    // int array[] = {0, 1, 4, 6, 8, 9, 12, 26, 37, 44, 54, 71};
    // int arraySize = sizeof(array);
    // int intSize = sizeof(array[0]);
    // int length = arraySize / intSize;

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
    for (int i = length; i > 0; i--) {
        BOOL sorted = TRUE;
        for (int j = 1; j < i; j++) {
            if (array[j - 1] > array[j]) {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;

                sorted = FALSE;
            }
        }

        if (sorted == TRUE) {
            break;
        }
    }
    //======下面是估算排序时间和验证排序的准确性,上面才是真正排序的代码=========

    c_end = clock();
    t_end = time(NULL);
    printf("\nThe sorting used %f ms by clock()\n",
           difftime(c_end, c_start) / CLOCKS_PER_SEC * 1000);
    printf("The sorting used %f s by time()\n", difftime(t_end, t_start));

    int prev = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < prev) {
            printf("\n========👎👎👎👎 not ascending order=============\n");
            return 0;
        }
        prev = array[i];
    }
    printf("\n========yes 👍👍👍👍👍 ascending order=============\n");

    free(array);

    return 0;
}

/**
The sorting used 21779.924000 ms by clock()
The sorting used 22.000000 s by time()
 */
// 基础的冒泡排序
int main222() {

    // int array[] = {71, 12, 9, 8, 26, 37, 44, 54};
    // int arraySize = sizeof(array);
    // int intSize = sizeof(array[0]);
    // int length = arraySize / intSize;

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
    for (int i = length; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            if (array[j - 1] > array[j]) {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
    //======下面是估算排序时间和验证排序的准确性,上面才是真正排序的代码=========

    c_end = clock();
    t_end = time(NULL);
    printf("\nThe sorting used %f ms by clock()\n",
           difftime(c_end, c_start) / CLOCKS_PER_SEC * 1000);
    printf("The sorting used %f s by time()\n", difftime(t_end, t_start));

    int prev = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < prev) {
            printf("\n========👎👎👎👎 not ascending order=============\n");
            return 0;
        }
        prev = array[i];
    }
    printf("\n========yes 👍👍👍👍👍 ascending order=============\n");

    free(array);

    return 0;
}

// 测试代码
int main10() {
    // printf("%d\n", 1111);

    int array[] = {71, 12, 9, 8, 26, 37, 44, 54};
    // printf("%ld\n", sizeof(array));
    //  calculate size in bytes
    int arraySize = sizeof(array);
    int intSize = sizeof(array[0]);
    // length
    int length = arraySize / intSize;

    /**
        printf("%d\n", arraySize);
        printf("%d\n", intSize);
        printf("%d\n", length);


    for (int i = 1; i < length; i++)
    {
        if (array[i - 1] > array[i])
        {
            int temp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = temp;
            // break;
        }
    }
    */

    // printf("%d\n", 2222);
    // printf(array);

    for (int i = length; i > 0; i--) {
        // printf("%d\n", i);
        // printf("%d\n", array[i]);
        for (int j = 1; j < i; j++) {

            // printf("%d\n", i);
            // printf("%d\n", j);

            // printf("%d\n", array[j - 1]);
            // printf("%d\n", array[j]);

            if (array[j - 1] > array[j]) {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }

        // printf("\n");
    }

    for (int i = 0; i < length; i++) {
        printf("%d_", array[i]);
        // printf("%d\n", i);
    }

    return 0;
}
