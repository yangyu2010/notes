#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int canPartition(int *nums, int numsSize);

/**
https://leetcode.cn/problems/partition-equal-subset-sum/

给你一个 只包含正整数 的 非空 数组 nums。
请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
 */

int main() {
    const int size = 5;
    int *nums = (int *)calloc(size, sizeof(int));

    int arrayNums[size] = {1, 5, 11, 5};
    // int arrayNums[size] = {1, 2, 5, 7, 19};
    for (int i = 0; i < size; i++) {
        nums[i] = arrayNums[i];
    }

    int result = canPartition(nums, size);
    printf("%d", result);

    return 0;
}

/**
{1, 5, 11, 5};

dp[i][j]
前i位刚好凑齐j
i ∈ [1, numsSize]，j ∈ [1, half]
状态转移方程
dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]]
比如j=6, i=2 
dp[2][1] = dp[1][1] = 1
dp[2][5] = dp[1][5] || dp[1][0] = 1
dp[2][6] = dp[1][6] || dp[1][1] = 1

  j 1 2 3 4 5 6 7 8 9 10 11
i
1   1 0 0 0 0 0 0 0 0 0  0
2   1 0 0 0 1 1 0 0 0 0  0
3   1 0 0 0 1 1 0 0 0 0  1
4   1 0 0 0 1 1 0 0 0 0  1
 */

int canPartition(int *nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum & 1) {
        return 0;
    }
    int target = sum >> 1;
    int dp[target + 1];
    memset(dp, 0, sizeof(int) * (target + 1));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[target] != 0;
}

// int canPartition(int *nums, int numsSize) {
//     if (nums == NULL || numsSize == 0) {
//         return 0;
//     }

//     int sum = 0, half = 0;
//     for (int i = 0; i < numsSize; i++) {
//         sum += nums[i];
//     }
//     if (sum & 1 == 1) {
//         return 0;
//     }
//     half = sum >> 1;

//     int dp[half + 1];
//     memset(dp, 0, sizeof(dp));
//     dp[0] = 1;
//     for (int j = 1; j <= half; j++) {
//         dp[j] = 0;
//     }

//     for (int i = 1; i <= numsSize; i++) {
//         for (int j = half; j > 0; j--) {
//             dp[j] = dp[j] || dp[j - nums[i - 1]];
//         }
//     }

//     return dp[half] > 0 ? 1 : 0;
// }

int canPartition2(int *nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum & 1 == 1) {
        return 0;
    }
    int capacity = sum >> 1;

    int dp[numsSize + 1][capacity + 1];
    for (int i = 0; i <= numsSize; i++) {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= capacity; j++) {
        dp[0][j] = INT_MIN;
    }

    for (int i = 1; i <= numsSize; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = fmax(dp[i - 1][j],
                                dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return dp[numsSize][capacity] > 0 ? 1 : 0;
}

int canPartition1(int *nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int sum = 0, half = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum & 1 == 1) {
        return 0;
    }
    int capacity = sum >> 1;

    int dp[half + 1];
    // memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for (int j = 1; j <= half; j++) {
        dp[j] = INT_MIN;
    }

    for (int i = 1; i <= numsSize; i++) {
        for (int j = half; j > 0; j--) {
            if (nums[i - 1] > j) {
                // dp[j] = dp[j]; 直接continue
                continue;
            }
            dp[j] = fmax(dp[j], dp[j - nums[i - 1]] + nums[i - 1]);
        }

        for (int i = 0; i <= half; i++) {
            printf("%d ", dp[i]);
        }
        printf("\n");
    }

    return dp[half] > 0 ? 1 : 0;
}