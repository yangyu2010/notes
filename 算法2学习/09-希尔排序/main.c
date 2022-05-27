#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int getStepSequenceSize(int *, int);
int *getStepSequence(int *, int, int);
void sort(int *, int, int);

/**
The sorting used 6.859000 ms by clock()
The sorting used 0.000000 s by time()
 */
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

    // int array_datas[] = {
    //     80, 82, 50, 11, 100, 30, 36, 71, 43, 94, 55, 21, 59, 3,  37, 24, 89,
    //     81, 90, 18, 52, 27,  42, 21, 54, 57, 2,  41, 29, 65, 96, 90, 24, 9,
    //     96, 22, 35, 70, 12,  39, 68, 1,  81, 36, 89, 88, 77, 16, 29, 8,  66,
    //     46, 71, 64, 63, 43,  55, 73, 92, 96, 44, 4,  98, 31, 81, 24, 78};

    // int arraySize = sizeof(array_datas);
    // int intSize = sizeof(array_datas[0]);
    // int length = arraySize / intSize;

    int length = 30000;
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

    int sequenceSize = getStepSequenceSize(array, length);
    int *sequenceArray = getStepSequence(array, length, sequenceSize);
    for (int i = 0; i < sequenceSize; i++) {
        sort(array, length, sequenceArray[i]);
    }

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

    printf("\n\n");
    for (int i = 0; i < sequenceSize; i++) {
        printf("%d,", sequenceArray[i]);
    }
    printf("\n\n");

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