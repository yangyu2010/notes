// #include <>
#include <stdio.h>
#include <string.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

// 记录下最后一次交换的位置
int main()
{

    // int array[] = {1, 4, 6, 0, 71, 12, 9, 8, 26, 37, 44, 54};

    // int array[] = {0, 1, 4, 6, 8, 9, 12, 26, 37, 44, 54, 71};
    int array[] = {4, 6, 8, 9, 0, 1, 12, 26, 37, 44, 54, 71};

    int arraySize = sizeof(array);
    int intSize = sizeof(array[0]);
    int length = arraySize / intSize;

    for (int i = length; i > 0; i--)
    {
        int sortedIndex = 0;
        for (int j = 1; j < i; j++)
        {
            if (array[j - 1] > array[j])
            {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;

                sortedIndex = j + 1;
            }
        }
        i = sortedIndex;
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d,", array[i]);
    }

    return 0;
}

// 冒泡排序(有序后提前退出)
int main3()
{

    // int array[] = {1, 4, 6, 0, 71, 12, 9, 8, 26, 37, 44, 54};

    int array[] = {0, 1, 4, 6, 8, 9, 12, 26, 37, 44, 54, 71};

    int arraySize = sizeof(array);
    int intSize = sizeof(array[0]);
    int length = arraySize / intSize;

    for (int i = length; i > 0; i--)
    {
        BOOL sorted = TRUE;
        for (int j = 1; j < i; j++)
        {
            if (array[j - 1] > array[j])
            {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;

                sorted = FALSE;
            }
        }

        if (sorted == TRUE)
        {
            break;
        }
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d,", array[i]);
    }

    return 0;
}

// 基础的冒泡排序
int main2()
{

    int array[] = {71, 12, 9, 8, 26, 37, 44, 54};

    int arraySize = sizeof(array);
    int intSize = sizeof(array[0]);
    int length = arraySize / intSize;

    for (int i = length; i > 0; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (array[j - 1] > array[j])
            {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d_", array[i]);
    }

    return 0;
}

// 测试代码
int main1()
{
    // printf("%d\n", 1111);

    int array[] = {71, 12, 9, 8, 26, 37, 44, 54};
    // printf("%ld\n", sizeof(array));
    //  calculate size in bytes
    int arraySize = sizeof(array);
    int intSize = sizeof(array[0]);
    // length
    int length = arraySize / intSize;

    /**
        printf("%d\n", arraySize);
        printf("%d\n", intSize);
        printf("%d\n", length);


    for (int i = 1; i < length; i++)
    {
        if (array[i - 1] > array[i])
        {
            int temp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = temp;
            // break;
        }
    }
    */

    // printf("%d\n", 2222);
    // printf(array);

    for (int i = length; i > 0; i--)
    {
        // printf("%d\n", i);
        // printf("%d\n", array[i]);
        for (int j = 1; j < i; j++)
        {

            // printf("%d\n", i);
            // printf("%d\n", j);

            // printf("%d\n", array[j - 1]);
            // printf("%d\n", array[j]);

            if (array[j - 1] > array[j])
            {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }

        // printf("\n");
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d_", array[i]);
        // printf("%d\n", i);
    }

    return 0;
}
