#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
最大连续子序列和
https://leetcode.cn/problems/maximum-subarray/

给定一个长度为 n 的整数序列，求它的最大连续子序列和
比如 –2、1、–3、4、–1、2、1、–5、4 的最大连续子序列和是 4 + (–1) + 2 + 1 = 6
*/

int maxSubArray(int *, int);
int maxSub(int *, int, int);

int main() {
    int numsSize = 9;
    int *nums = (int *)calloc(numsSize, sizeof(int));
    int array[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    for (int i = 0; i < numsSize; i++) {
        nums[i] = array[i];
    }

    int max = maxSubArray(nums, numsSize);
    printf("%d", max);

    return 0;
}

int maxSubArray(int *nums, int numsSize) {
    int max = maxSub(nums, 0, numsSize);
    return max;
}

int maxSub(int *nums, int begin, int end) {
    if (end - begin == 1) {
        return nums[begin];
    }

    int middle = (begin + end) >> 1;

    int leftMaxNum = INT_MIN;
    int leftSumNum = 0;
    for (int i = middle - 1; i >= begin; i--) {
        leftSumNum += nums[i];
        if (leftSumNum > leftMaxNum) {
            leftMaxNum = leftSumNum;
        }
    }

    int rightMaxNum = INT_MIN;
    int rightSumNum = 0;
    for (int i = middle; i < end; i++) {
        rightSumNum += nums[i];
        if (rightSumNum > rightMaxNum) {
            rightMaxNum = rightSumNum;
        }
    }

    int middleMaxSub = leftMaxNum + rightMaxNum;
    int leftMaxSub = maxSub(nums, begin, middle);
    int rightMaxSub = maxSub(nums, middle, end);

    return (middleMaxSub > leftMaxSub ? middleMaxSub : leftMaxSub) > rightMaxSub
               ? (middleMaxSub > leftMaxSub ? middleMaxSub : leftMaxSub)
               : rightMaxSub;
}

/**
int maxSubArray(int *nums, int numsSize) {
    int max = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        int size = 0;
        for (int j = i; j < numsSize; j++) {
            size += nums[j];
            if (size > max) {
                max = size;
            }
        }
    }

    return max;
}
*/