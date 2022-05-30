#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void sort(int *, int, int);
int pivotIndex(int *, int, int);

int main1() {
    int i;
    /* It returns the same sequence of random number
    on every execution of the program. */
    printf(" Random Numbers are: \n");
    for (i = 0; i < 50; i++) {
        printf(" %d", rand() % 9);
    }
    return 0;
}

/*
The sorting used 10.754000 ms by clock()
The sorting used 0.000000 s by time()
*/
int main() {

    // int array_datas[] = {6, 2, 1, 10, 21, 19, 5, 12, 9};
    // int array_datas[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    // int array_datas[] = {4, 6, 6, 6, 8, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    // int array_datas[] = {13, 13, 20, 76, 22, 56, 78, 26, 91, 59, 33, 62,
    //                      63, 93, 68, 39, 65, 86, 41, 88, 20, 91, 93};
    // int array_datas[] = {13, 76, 22, 56, 78, 26};

    // int array_datas[] = {6, 6, 6, 6, 6, 6, 6};
    // int array_datas[] = {7, 1, 2, 3, 4, 5, 6};

    // int arraySize = sizeof(array_datas);
    // int intSize = sizeof(array_datas[0]);
    // int length = arraySize / intSize;

    // int *array = (int *)calloc(length, sizeof(int));
    // for (int i = 0; i < length; i++) {
    //     array[i] = array_datas[i];
    // }

    // for (int i = 0; i < length; i++) {
    //     printf("%d,", array[i]);
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
    sort(array, 0, length);
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

void sort(int *array, int begin, int end) {
    // 当小于两个元素 就直接返回
    if (end - begin < 2) {
        return;
    }

    int pivot_index = pivotIndex(array, begin, end);
    sort(array, begin, pivot_index);
    sort(array, pivot_index + 1, end);
}

int pivotIndex(int *array, int begin, int end) {
    // 选择[begin, end)中一个随机位置来当作轴点
    // 加入这个交互逻辑 其他逻辑不变
    // 之前是取第一个当做轴点
    int swapIndex = begin + rand() % (end - begin);
    int temp = array[swapIndex];
    array[swapIndex] = array[begin];
    array[begin] = temp;

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
