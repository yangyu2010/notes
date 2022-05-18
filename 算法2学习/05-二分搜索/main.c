#include <stdio.h>
#include <string.h>

// #include <stdbool.h>
// #include <stdio.h>
#include <stdlib.h> // pulls in declaration of malloc, free
// #include <string.h> // pulls in declaration for strlen.

// https://stackoverflow.com/questions/12131925/getting-the-size-of-a-malloc-only-with-the-returned-pointer

int indexOf(int *array, int size, int value) {
    if (array == NULL || sizeof(array) == 0) {
        return -1;
    }

    int begin = 0;
    int end = size;

    while (begin < end) {
        int mid = (begin + end) >> 1;
        if (array[mid] > value) {
            // end = mid - 1;
            // 不能是mid-1
            // [begin, end)
            // 开始是开区间 结束是闭区间
            end = mid;
        } else if (array[mid] < value) {
            begin = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    // int array[] = {0, 1, 4, 6, 8, 9, 12, 26, 37, 44, 54, 71};

    int size = 10;
    int *array = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    // printf("%d\n", indexOf(array, size, 0));
    // printf("%d\n", indexOf(array, size, 1));
    // printf("%d\n", indexOf(array, size, 2));
    // printf("%d\n", indexOf(array, size, 3));
    // printf("%d\n", indexOf(array, size, 50));
    // printf("%d\n", indexOf(array, size, 51));
    printf("%d\n", indexOf(array, size, 4));
    // printf("%d\n", indexOf(array, size, 98));
    // printf("%d\n", indexOf(array, size, 99));
    // printf("%d\n", indexOf(array, size, 100));
    // printf("%d\n", indexOf(array, size, 101));
    // printf("%d\n", indexOf(array, size, 102));

    free(array);

    // printf("%d", i1);
    return 0;
}