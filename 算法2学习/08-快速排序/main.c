#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int *, int, int);
int pivotIndex(int *, int, int);

int main() {

    // int array_datas[] = {6, 2, 1, 10, 21, 19, 5, 12, 9};
    // int array_datas[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    int array_datas[] = {4, 6, 6, 6, 8, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    // int array_datas[] = {13, 13, 20, 76, 22, 56, 78, 26, 91, 59, 33, 62,
    //                      63, 93, 68, 39, 65, 86, 41, 88, 20, 91, 93};
    // int array_datas[] = {13, 76, 22, 56, 78, 26};

    // int array_datas[] = {6, 6, 6, 6, 6, 6, 6};
    // int array_datas[] = {7, 1, 2, 3, 4, 5, 6};

    int arraySize = sizeof(array_datas);
    int intSize = sizeof(array_datas[0]);
    int length = arraySize / intSize;

    int *array = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        array[i] = array_datas[i];
    }

    for (int i = 0; i < length; i++) {
        printf("%d,", array[i]);
    }

    sort(array, 0, length);

    printf("\n");

    for (int i = 0; i < length; i++) {
        printf("%d,", array[i]);
    }

    free(array);

    return 0;
}

void sort(int *array, int begin, int end) {
    if (end - begin < 2) {
        return;
    }

    int pivot_index = pivotIndex(array, begin, end);
    sort(array, begin, pivot_index);
    sort(array, pivot_index + 1, end);
}

int pivotIndex(int *array, int begin, int end) {
    int pivot_value = array[begin];
    end--;

    int isRight = 1;
    while (begin < end) {
        if (isRight) {
            /*
            if (array[end] >= pivot_value)
            这里不能等于
            等于后 end 一直在减减
            导致子序列分配不均匀

            {6, 6, 6, 6, 6, 6, 6}
            begin = 0;
            end = 6; 已经在上面--了
            这时如果有=号
            end会一直在减减 直到=0
            这时begin=end=0结束循环

            这时pivot_index = 0
            sort(array, begin, pivot_index);
            sort(array, pivot_index + 1, end);
            [0, 0)
            [1, end)
            导致所有的第一个sort(array, begin, pivot_index)一直是[0, 0)
            */
            if (array[end] > pivot_value) {
                end--;
            } else {
                array[begin] = array[end];
                begin++;
                isRight = 0;
            }
        } else {
            /*
            if (array[begin] <= pivot_value)
            同理这里也不有=号
            如 {7, 1, 2, 3, 4, 5, 6};
            */
            if (array[begin] < pivot_value) {
                begin++;
            } else {
                array[end] = array[begin];
                end--;
                isRight = 1;
            }
        }
    }

    array[begin] = pivot_value;
    return begin;
}
