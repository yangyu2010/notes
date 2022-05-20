#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 查找Value在array应该插入的位置
 * 就是array中第一个元素大于(必须大于 不能等于)Value的位置
 0 1 2 2 3 3 3 4 5 ([0, 8))
 如果要插入2(Value) 返回4

第一次查找中间
    begin = 0;
    end = 8;
    mid = (begin + end) >> 1 = 4;
    array[mid] = 3;
    Value < array[mid]; 
    //如果要插入的值(Value)小于中间位置的值, 去左边,begin不变, end=mid 
    
第二次查找 
    begin = 0; 
    end = mid = 4; 
    mid = 2; 
    array[mid] = 2; 
    Value >= array[mid]; 
    //如果要插入的值(Value)大于中间位置的值, 去右边,begin=mid+1, end不变 

第三次查找 
    begin = min + 1 = 3;
    end = 4; 
    mid = 3;
    array[mid] = 2;
    Value >= array[mid]; 
    //如果要插入的值(Value)大于中间位置的值, 去右边, begin=mid+1, end不变 

准备第四次查找 
    begin = min + 1 = 4; 
    end = 4; 
    break;
*/
int indexOf(int *array, int size, int value) {
    if (array == NULL || sizeof(array) == 0) {
        return -1;
    }

    int begin = 0;
    int end = size;

    while (begin < end) {
        int mid = (begin + end) >> 1;
        if (value < array[mid]) {
            end = mid;
        } else {
            begin = mid + 1;
        }

        // if (array[mid] > value) {
        //     // end = mid - 1;
        //     // 不能是mid-1
        //     // [begin, end)
        //     // 开始是开区间 结束是闭区间
        //     end = mid;
        // } else if (array[mid] < value) {
        //     begin = mid + 1;
        // } else {
        //     return mid;
        // }
    }

    return begin;
}


int main() {
    int array_datas[] = {1, 1, 1, 4, 6, 8, 9, 12, 26, 37, 44, 54, 71};
    // 0 1 2 2 3 3 3 4 5
    int arraySize = sizeof(array_datas);
    int intSize = sizeof(array_datas[0]);
    int length = arraySize / intSize;

    int *array = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        array[i] = array_datas[i];
    }

    printf("%d\n", indexOf(array, length, 90));

    free(array);

    return 0;
}


int main1() {
    int size = 9;
    int *array = (int *)calloc(size, sizeof(int));
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;
    array[3] = 2;
    array[4] = 3;
    array[5] = 3;
    array[6] = 3;
    array[7] = 4;
    array[8] = 5;

    printf("%d\n", indexOf(array, size, 2));

    free(array);
}
