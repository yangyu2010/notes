#include <stdio.h>
#include <string.h>

int main()
{

    // int array[] = {1, 4, 6, 0, 71, 12, 9, 8, 26, 37, 44, 54};

    // int array[] = {0, 1, 4, 6, 8, 9, 12, 26, 37, 44, 54, 71};
    // int array[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};

    int array[] = {12, 4, 6, 8, 12, 9, 0, 1};

    int arraySize = sizeof(array);
    int intSize = sizeof(array[0]);
    int length = arraySize / intSize;

    for (int i = length; i > 0; i--)
    {
        int maxValueIndex = 0;
        for (int j = 1; j < i; j++)
        {
            if (array[maxValueIndex] <= array[j])
            {
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

    for (int i = 0; i < length; i++)
    {
        printf("%d,", array[i]);
    }

    return 0;
}