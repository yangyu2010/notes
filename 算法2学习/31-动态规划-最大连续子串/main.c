#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int *, int);

int main() {
    // int numsSize = 9;
    // int *nums = (int *)calloc(numsSize, sizeof(int));
    // int array[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // for (int i = 0; i < numsSize; i++) {
    //     nums[i] = array[i];
    // }

    int numsSize = 1;
    int *nums = (int *)calloc(numsSize, sizeof(int));
    int array[1] = {1};
    for (int i = 0; i < numsSize; i++) {
        nums[i] = array[i];
    }

    int max = maxSubArray(nums, numsSize);
    printf("\n%d", max);

    return 0;
}

int maxSubArray(int *nums, int numsSize) {
    int max = nums[0];
    int prev = max;

    for (int i = 1; i < numsSize; i++) {
        int current = nums[i];
        if (prev > 0) {
            current += prev;
        }
        prev = current;

        if (current > max) {
            max = current;
        }
    }

    return max;
}

// int maxSubArray(int *nums, int numsSize) {
//     int *dp = (int *)calloc(numsSize, sizeof(int));
//     dp[0] = nums[0];
//     int max = dp[0];

//     for (int i = 1; i < numsSize; i++) {
//         if (dp[i - 1] < 0) {
//             dp[i] = nums[i];
//         } else {
//             dp[i] = dp[i - 1] + nums[i];
//         }
//         if (dp[i] > max) {
//             max = dp[i];
//         }
//     }

//     return max;
// }
