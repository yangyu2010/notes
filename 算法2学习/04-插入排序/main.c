#include <stdio.h>
#include <string.h>

int main() {
    //int array[] = {12, 4, 6, 8, 12, 9, 0, 1};
    int array[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};

    int arraySize = sizeof(array);
    int intSize = sizeof(array[0]);
    int length = arraySize / intSize;

    // 从1位置开始比较前一位
    // 如果小于 就交互
    for (int i = 1; i < length; i++) {
        // 记录下当前的位置
        // 一直比较到1的位置 index-1就是位置1 
        // 要和当前的值做比较
        int index = i;
        int value = array[index];
        while (index > 0 && value < array[index - 1]) {
            // int temp = array[index];
            // array[index] = array[index - 1];
            // array[index - 1] = temp;
            array[index] = array[index - 1];
            index -= 1;
        }

        array[index] = value;
    }

    for (int i = 0; i < length; i++) {
        printf("%d,", array[i]);
    }

    return 0;
}

int main1() {

    // int array[] = {1, 4, 6, 0, 71, 12, 9, 8, 26, 37, 44, 54};

    // int array[] = {0, 1, 4, 6, 8, 9, 12, 26, 37, 44, 54, 71};
    int array[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};

    // 8位
    // int array[] = {12, 4, 6, 8, 12, 9, 0, 1};

    int arraySize = sizeof(array);
    int intSize = sizeof(array[0]);
    int length = arraySize / intSize;

    // 从1位置开始比较前一位
    // 如果小于 就交互
    for (int i = 1; i < length; i++) {
        // 记录下当前的位置
        // 一直比较到1的位置 index-1就是位置1和位置0比较
        int index = i;
        while (index > 0 && array[index] < array[index - 1]) {
            int temp = array[index];
            array[index] = array[index - 1];
            array[index - 1] = temp;

            index -= 1;
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%d,", array[i]);
    }

    return 0;
}