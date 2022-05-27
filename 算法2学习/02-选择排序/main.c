#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
The sorting used 783.326000 ms by clock()
The sorting used 1.000000 s by time()
*/
int main() {

    // int array[] = {1, 4, 6, 0, 71, 12, 9, 8, 26, 37, 44, 54};

    // int array[] = {0, 1, 4, 6, 8, 9, 12, 26, 37, 44, 54, 71};
    // int array[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};
    // int array[] = {12, 4, 6, 8, 12, 9, 0, 1};
    // int arraySize = sizeof(array);
    // int intSize = sizeof(array[0]);
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

    for (int i = length; i > 0; i--) {
        int maxValueIndex = 0;
        for (int j = 1; j < i; j++) {
            if (array[maxValueIndex] <= array[j]) {
                maxValueIndex = j;
            }
        }

        // printf("%d,", i - 1);
        // printf("%d,", maxValueIndex);
        // printf("%d,", array[maxValueIndex]);
        // printf("\n");

        int temp = array[maxValueIndex];
        array[maxValueIndex] = array[i - 1];
        array[i - 1] = temp;
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

    return 0;
}