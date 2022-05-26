#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getStepSequenceSize(int *, int);
int *getStepSequence(int *, int, int);
void sort(int *, int, int);

int main() {

    // int array_datas[] = {6, 2, 1, 10, 21, 19, 5, 12, 9};
    // int array_datas[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    // int array_datas[] = {4, 6, 6, 6, 8, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71,
    // 99};
    int array_datas[] = {13, 13, 20, 76, 22, 56, 78, 26, 91, 59, 33, 62,
                         63, 93, 68, 39, 65, 86, 41, 88, 20, 91, 93};
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

    //
    int sequenceSize = getStepSequenceSize(array, length);
    int *sequenceArray = getStepSequence(array, length, sequenceSize);
    for (int i = 0; i < sequenceSize; i++) {
        sort(array, length, sequenceArray[i]);
    }

    printf("\n");

    for (int i = 0; i < length; i++) {
        printf("%d,", array[i]);
    }

    free(array);
    free(sequenceArray);
    return 0;
}

/**
 * @brief 获取步长数组的长度
 *
 * @param array 要排序的数组
 * @param size 要排序的数组Size
 * @return int 步长数组的长度
 */
int getStepSequenceSize(int *array, int size) {
    int length = size;

    int count = 0;
    while ((length /= 2) > 0) {
        count += 1;
    }

    return count;
}

/**
 * @brief 获取步长数组
 * 数组长度一直除以2, 直到1
 *
 * @param array 要排序的数组
 * @param size 要排序的数组Size
 * @param sequenceSize 步长数组的Size
 * @return int* 步长数组数组
 */
int *getStepSequence(int *array, int size, int sequenceSize) {
    int *sequenceArray = (int *)calloc(sequenceSize, sizeof(int));
    int length = size;
    for (int i = 0; i < sequenceSize; i++) {
        length /= 2;
        sequenceArray[i] = length;
    }

    printf("\n");
    for (int i = 0; i < sequenceSize; i++) {
        printf("%d,", sequenceArray[i]);
    }
    printf("\n");

    return sequenceArray;
}

/**
 * @brief 根据步长来把数组array分成step列来排序
 *
 * @param array 数组
 * @param size 数组的长度 (int *获取不到长度)
 * @param step 步长
 */
void sort(int *array, int size, int step) {
    for (int col = 0; col < step; col++) {
        for (int beigin = col + step; beigin < size; beigin += step) {
            int cur = beigin;
            while (cur > 0 && array[cur] < array[cur - step]) {
                int temp = array[cur];
                array[cur] = array[cur - step];
                array[cur - step] = temp;

                cur -= step;
            }
        }
    }
}