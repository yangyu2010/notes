#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int *, int);

int main() {
    int numsSize = 9;
    int *nums = (int *)calloc(numsSize, sizeof(int));
    // int array[9] = {10, 9, 2, 5, 3, 7, 101, 18, 5};
    int array[9] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
    for (int i = 0; i < numsSize; i++) {
        nums[i] = array[i];
    }

    // int numsSize = 1;
    // int *nums = (int *)calloc(numsSize, sizeof(int));
    // int array[1] = {1};
    // for (int i = 0; i < numsSize; i++) {
    //     nums[i] = array[i];
    // }

    int max = lengthOfLIS(nums, numsSize);
    printf("\n%d", max);

    return 0;
}

int lengthOfLIS(int *nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    int *dp = (int *)calloc(numsSize, sizeof(int));
    int max = dp[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && (dp[j] + 1 > dp[i])) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}