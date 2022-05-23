#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *leftArray;
void sort(int *, int, int);
void merge(int *, int, int, int);

int main() {
    int array_datas[] = {2, 1, 10, 21, 19, 6, 5, 12};
    // int array_datas[] = {2, 1, 10, 21, 19, 6, 5, 12, 9};
    // int array_datas[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    // int array_datas[] = {4, 6, 6, 6, 8, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    //int array_datas[] = {13, 76, 22, 56, 78, 26, 91, 59, 33, 62,
    //                     63, 93, 68, 39, 65, 86, 41, 88, 20};
    // int array_datas[] = {13, 76, 22, 56, 78, 26};

    // {2, 1, 10, 21, 19, 6, 5, 12, 9};
    // {1, 10, 2, 21, 19, 6, 5, 12, 9};
    // 0   1   2
    int arraySize = sizeof(array_datas);
    int intSize = sizeof(array_datas[0]);
    int length = arraySize / intSize;

    int *array = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        array[i] = array_datas[i];
    }

    leftArray = (int *)calloc(length, sizeof(int) << 1);
    sort(array, 0, length);

    for (int i = 0; i < length; i++) {
        printf("%d,", array[i]);
    }

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