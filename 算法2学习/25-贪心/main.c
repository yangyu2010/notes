#include <stdio.h>
#include <stdlib.h>

/**
假设有 25 分、10 分、5 分、1 分的硬币，现要找给客户 41
分的零钱，如何办到硬币个数最少?
*/
int main() {
    // int array[4] = {25, 20, 5, 1};
    int array[4] = {25, 10, 5, 1};
    int arraySize = sizeof(array);
    int intSize = sizeof(array[0]);
    int length = arraySize / intSize;

    int capacity = 41;
    int count = 0, volume = 0, index = 0;
    while (index < length) {
        int newVolume = volume + array[index];
        if (newVolume <= capacity) {
            volume = newVolume;
            count++;
            printf("选择了硬币是 %d\n", array[index]);
            continue;
        }
        index++;
    }

    // for (int i = 0; i < length; i++) {
    //     int newVolume = volume + array[i];
    //     if (newVolume <= capacity) {
    //         volume = newVolume;
    //         count++;

    //         printf("选择了硬币是 %d\n", array[i]);
    //         i -= 1;
    //     }
    // }

    printf("总共 %d 个\n", count);
    printf("总共 %d 钱\n", volume);

    return 0;
}

/**
在北美洲东南部，有一片神秘的海域，是海盗最活跃的加勒比海
有一天，海盗们截获了一艘装满各种各样古董的货船，每一件古董都价值连城，一旦打碎就失去了它的价值
海盗船的载重量为 W，每件古董的重量为
wi，海盗们该如何把尽可能多数量的古董装上海盗船?
比如 W 为 30，wi 分别为3、5、4、10、7、14、2、11
*/
int main1() {
    int weights[8] = {3, 5, 4, 10, 7, 14, 2, 11};
    int arraySize = sizeof(weights);
    int intSize = sizeof(weights[0]);
    int length = arraySize / intSize;

    /// 先排序
    for (int i = length; i > 0; i--) {
        int maxValueIndex = 0;
        for (int j = 1; j < i; j++) {
            if (weights[maxValueIndex] <= weights[j]) {
                maxValueIndex = j;
            }
        }
        int temp = weights[maxValueIndex];
        weights[maxValueIndex] = weights[i - 1];
        weights[i - 1] = temp;
    }

    int capacity = 30;
    int count = 0, weight = 0;
    for (int i = 0; i < length; i++) {
        int newWeight = weight + weights[i];
        if (newWeight <= capacity) {
            weight = newWeight;
            count++;
            printf("选择了重量是 %d 的物品\n", weights[i]);
        }
    }
    printf("总共 %d 个\n", count);
    printf("总共 %d 重量\n", weight);

    return 0;
}
