#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *leftArray;
void sort(int *, int, int);
void merge(int *, int, int, int);

/*
The sorting used 13.548000 ms by clock()
The sorting used 0.000000 s by time()
*/
int main() {
    // int array_datas[] = {2, 1, 10, 21, 19, 6, 5, 12};
    // int array_datas[] = {2, 1, 10, 21, 19, 6, 5, 12, 9};
    // int array_datas[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    // int array_datas[] = {4, 6, 6, 6, 8, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    // int array_datas[] = {13, 76, 22, 56, 78, 26, 91, 59, 33, 62,
    //                     63, 93, 68, 39, 65, 86, 41, 88, 20};
    // int array_datas[] = {13, 76, 22, 56, 78, 26};

    // {2, 1, 10, 21, 19, 6, 5, 12, 9};
    // {1, 10, 2, 21, 19, 6, 5, 12, 9};
    // 0   1   2
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
        array[i] = random() % 100000;
    }
    for (int i = 0; i < length; i++) {
        printf("%d,", array[i]);
    }
    time_t c_start, t_start, c_end, t_end;
    c_start = clock();    //!< 单位为ms
    t_start = time(NULL); //!< 单位为s

    leftArray = (int *)calloc(length, sizeof(int) << 1);
    sort(array, 0, length);

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
    free(leftArray);
    return 0;
}

void sort(int *array, int begin, int end) {
    if (end - begin <= 1) {
        return;
    }

    int mid = (begin + end) >> 1;
    sort(array, begin, mid);
    sort(array, mid, end);
    merge(array, begin, mid, end);
}

void merge(int *array, int begin, int mid, int end) {
    // int leftIndex = begin;
    // int leftEnd = mid;
    int leftIndex = 0, leftEnd = mid - begin;
    int rightIndex = mid, rightEnd = end;

    int currentIndex = begin;

    for (int i = leftIndex; i < leftEnd; i++) {
        leftArray[i] = array[begin + i];
    }
    /*
    当数组左边还需要比较时, 进入判断
    如果左边不需要判断了, 或者说左边的数据已经全部处理完成后, 直接退出即可,
    右边的数据保持原样.

    当左边的数据大于(为了稳定排序, 不能等于)右边时, 把右边的值给当前位置
    同时判断右边是否还有值
    */
    while (leftIndex < leftEnd) {
        if (leftArray[leftIndex] > array[rightIndex] && rightIndex < rightEnd) {
            array[currentIndex] = array[rightIndex];
            currentIndex++;
            rightIndex++;
        } else {
            array[currentIndex] = leftArray[leftIndex];
            currentIndex++;
            leftIndex++;
        }
    }
}