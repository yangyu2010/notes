#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findTargetSumWays(int *, int, int);

/**
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-'
然后串联起来得到表达式 "+2-1" 。 返回可以通过上述方法构造的、运算结果等于
target 的不同 表达式 的数目。

示例 1：

输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

示例 2：

输入：nums = [1], target = 1
输出：1

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/**
dp[i][j]前i位凑集j有几种方式

nums = [1,1,1,1,1], target = 3

dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j + nums[i - 1]]

dp[0][0] = 1

dp[1][-1] = dp[0][-2] + dp[0][0] = 1
dp[1][0] = dp[0][-1] + dp[0][1] = 0 + 0 = 0
dp[1][1] = dp[1][0] + dp[1][-1] = 0 + 1 = 1
dp[1][2] = dp[0][1] + dp[0][3] = 0 + 0 = 0
dp[1][3] = dp[0][2] + dp[0][4] = 0 + 0 = 0

dp[2][-3] = dp[1][-4] + dp[1][-2] = 0 + 0 = 0
dp[2][-2] = dp[1][-3] + dp[1][-1] = 0 + 1 = 1
dp[2][-1] = dp[1][-2] + dp[1][0] = 0 + 0 = 0
dp[2][0] = dp[1][-1] + dp[1][1] = 1 + 1 = 2
dp[2][1] = dp[1][0] + dp[1][2] = 0 + 0 = 0
dp[2][2] = dp[1][1] + dp[1][3] = 1 + 0 = 0
dp[2][3] = dp[1][2] + dp[1][4] = 0 + 0 = 0

dp[3][-2] = dp[2][-3] + dp[2][-1] = 0 + 0 = 0
dp[3][-1] = dp[2][-2] + dp[2][0] = 1 + 2 = 3
dp[3][0] = dp[2][-1] + dp[2][1] = 0 + 0 = 0
dp[3][1] = dp[2][0] + dp[2][3] = 2 + 0 = 2
dp[3][2] = dp[2][1] + dp[2][3] = 0 + 0 = 0
dp[3][3] = dp[2][2] + dp[2][4] = 0 + 0 = 0

dp[4][-1] = dp[3][-2] + dp[3][0] = 0 + 0 = 0
dp[4][0] = dp[3][-1] + dp[3][1] = 0 + 0 = 0
dp[4][1] = dp[3][0] + dp[3][2] = 0 + 0 = 0
dp[4][2] = dp[3][1] + dp[3][3] = 2 + 0 = 2
dp[4][3] = dp[3][2] + dp[3][4] = 0 + 0 = 0
dp[4][4] = dp[3][3] + dp[3][5] = 0 + 0 = 0

dp[5][0] = dp[4][-1] + dp[4][1] = 0 + 0 = 0
dp[5][1] = dp[4][0] + dp[4][2] = 0 + 2 = 2
dp[5][2] = dp[4][1] + dp[4][3] = 0 + 0 = 0
dp[5][3] = dp[4][2] + dp[4][4] = 2 + 0 = 2


  j 0 1 2 3
i
0   1 0 0 0
1   0 1 0 0
2   2 0 1 0
3   0 1 0 1
4   0 0 2 0
5   0 2 0 2


  j 1 2 3
i
1   1 0 0
2   0 1 0
3   1 0 1
4   0 2 0
5   2 0 2

  j 0 1 2 3
i
0   1 0 0 0
1   0 1 0 0
2   2 0 1 0
3   0 1 0 1
4   0 0 2 0
5   0 2 0 2

 */

int main() {
    const int size = 5;
    int *nums = (int *)calloc(size, sizeof(int));

    int arrayNums[size] = {1, 1, 1, 1, 1};
    for (int i = 0; i < size; i++) {
        nums[i] = arrayNums[i];
    }

    int result = findTargetSumWays(nums, size, 3);
    printf("%d", result);

    return 0;
}

int findTargetSumWays(int *nums, int numsSize, int target) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (abs(target) > abs(sum)) {
        return 0;
    }

    int len = sum << 1;
    int dp[len + 1];
    memset(dp, 0, sizeof(dp));
    dp[len >> 1] = 1;

    for (int i = 1; i <= numsSize; i++) {
        for (int j = sum; j >= -sum; j--) {
            if (j - nums[i - 1] + sum < 0) {
                dp[j + sum] = dp[j + nums[i - 1] + sum];
            } else if (j + nums[i - 1] + sum > len) {
                dp[j + sum] = dp[j - nums[i - 1] + sum];
            } else {
                dp[j + sum] =
                    dp[j - nums[i - 1] + sum] + dp[j + nums[i - 1] + sum];
            }
        }
    }
    return dp[len];
}

/**
int findTargetSumWays(int *nums, int numsSize, int target) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (abs(target) > abs(sum)) {
        return 0;
    }

    int len = sum << 1;
    int dp[numsSize + 1][len + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][len >> 1] = 1;

    for (int i = 0; i <= numsSize; i++) {
        for (int j = 0; j <= len; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    printf("-----------------\n");

    for (int i = 1; i <= numsSize; i++) {
        for (int j = -sum; j <= sum; j++) {

            // if((j+nums[i]) > sum) {//+不成立 加上当前数大于了sum
            // 只能减去当前的数 	dp[i][j+sum] = dp[i-1][j-nums[i]+sum]+0;
            // }else if((j-nums[i]) < -sum) {//-不成立  减去当前数小于-sum
            // 只能加上当前的数 	dp[i][j+sum] = dp[i-1][j+nums[i]+sum]+0;
            // }else
            // {//+-都可以 	dp[i][j+sum] =
            // dp[i-1][j+nums[i]+sum]+dp[i-1][j-nums[i]+sum];
            // }

            if (j - nums[i - 1] + sum < 0) {
                dp[i][j + sum] = dp[i - 1][j + nums[i - 1] + sum];
            } else if (j + nums[i - 1] + sum > len) {
                dp[i][j + sum] = dp[i - 1][j - nums[i - 1] + sum];
            } else {
                dp[i][j + sum] = dp[i - 1][j - nums[i - 1] + sum] +
                                 dp[i - 1][j + nums[i - 1] + sum];
            }

            // printf("(%d, %d) = %d; ", i, j, dp[i][j]);
            // printf("%d ", dp[i][j]);
        }
        // printf("\n");
    }

    for (int i = 0; i <= numsSize; i++) {
        for (int j = 0; j <= len; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    printf("-----------------\n");

    return dp[numsSize][sum + target];
}

// int findTargetSumWays(int *nums, int numsSize, int target) {
//     int dp[target + 1];
//     memset(dp, 0, sizeof(int) * (target + 1));
//     dp[0] = 1;
//     for (int i = 0; i < numsSize; i++) {
//         for (int j = target; j >= 0; j--) {
//             dp[j] = dp[j - nums[i - 1]] + dp[-j + nums[i - 1]];
//         }
//     }

//     return dp[target];
// }
*/