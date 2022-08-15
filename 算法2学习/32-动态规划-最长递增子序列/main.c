#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int *, int);

/**
300. 最长递增子序列

给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7]
是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1


来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

int main() {
    int numsSize = 9;
    int *nums = (int *)calloc(numsSize, sizeof(int));
    int array[9] = {10, 9, 2, 5, 3, 7, 101, 18, 5};
    // int array[9] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
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

int lengthOfLIS1(int *nums, int numsSize) {
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

/**
◼ 把每个数字看做是一张扑克牌，从左到右按顺序处理每一个扑克牌
将它压在(从左边数过来)第一个牌顶 ≥ 它的牌堆上面
如果找不到牌顶 ≥ 它的牌堆，就在最右边新建一个牌堆，将它放入这个新牌堆中
当处理完所有牌，最终牌堆的数量就是最长上升子序列的长度
*/
int lengthOfLIS2(int *nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int *arr = (int *)calloc(numsSize, sizeof(int));
    int len = 0;
    for (int i = 0; i < numsSize; i++) {
        int bl = 0;
        for (int j = 0; j < len; j++) {
            if (arr[j] >= nums[i]) {
                arr[j] = nums[i];
                bl = 1;
                break;
            }
        }
        if (bl == 0) {
            arr[len] = nums[i];
            len++;
        }
    }
    return len;
}

int lengthOfLIS(int *nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    
    int *arr = (int *)calloc(numsSize, sizeof(int));
    int len = 0;
    for (int i = 0; i < numsSize; i++) {
        int begin = 0;
        int end = len;
        while (begin < end) {
            int mid = (begin + end) >> 1;
            if (nums[i] <= arr[mid]) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        arr[begin] = nums[i];
        if (begin == len) {
            len++;
        }
    }
    return len;
}