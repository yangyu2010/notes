// #include <>
#include <stdio.h>
#include <string.h>

int main()
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
