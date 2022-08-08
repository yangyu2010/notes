#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int select(int *, int, int *, int, int);

/**
有 n 件物品和一个最大承重为 W 的背包，每件物品的重量是 𝑤i、价值是 𝑣i
在保证总重量不超过 W 的前提下，选择某些物品装入背包，背包的最大总价值是多少?
注意:每个物品只有 1 件，也就是每个物品只能选择 0 件或者 1 件


假设 dp(i, j) 是 最大承重为 j、有前 i 件物品可选 时的最大总价值，i ∈ [1, n]，j ∈
[1, W] 初始值 dp(i, 0) = 0, dp(0, j) = 0 如果 j < weights[i – 1]，那么 dp(i, j)
= dp(i – 1, j) 如果 j ≥ weights[i – 1]，那么 dp(i, j) = max { dp(i – 1, j), dp(i
– 1, j – weights[i – 1]) + values[i – 1] }

int values[5] = {6, 3, 5, 4, 6};
int weight[5] = {2, 2, 6, 5, 4};

dp(1, 1) 最大承重为1, 有前1件物品可选 0
dp(2, 1) 最大承重为1, 有前2件物品可选 0
.
.
.
dp(5, 1) 最大承重为1, 有前5件物品可选 0

dp(1, 2) 最大承重为2, 有前1件物品可选 最大价值是6
dp(2, 2) 最大承重为2, 有前2件物品可选 最大价值是6
    1. 选择第2件物品 此时最大价值是3 + dp(i - 1, j - 3) = 3
    2. 不选择第2件物品 此时最大价值是 dp(i - i, j) = dp(1, 2) = 6
    在1和2中选择最大的一个

   j 0 1 2 3 4 5 6  7  8  9  10
i
0    0 0 0 0 0 0 0  0  0  0  0
1    0 0 6 6 6 6 6  6  6  6  6
2    0 0 6 6 9 9 9  9  9  9  9
3    0 0 6 6 9 9 9  9  11 11 14
4    0 0 6 6 9 9 9  10 11 13 14
5    0 0 6 6 9 9 12 12 15 15 15
 */

int main() {
    const int size = 5;
    int *values = (int *)calloc(size, sizeof(int));
    int *weights = (int *)calloc(size, sizeof(int));

    int arrayValues[size] = {6, 3, 5, 4, 6};
    int arrayWeight[size] = {2, 2, 6, 5, 4};
    for (int i = 0; i < size; i++) {
        values[i] = arrayValues[i];
        weights[i] = arrayWeight[i];
    }

    int max = select(values, size, weights, size, 10);
    printf("%d", max);

    return 0;
}

int select1(int *values, const int valuesCount, int *weights,
            const int weightsCount, const int capacity) {
    if (values == NULL || weights == NULL || valuesCount != weightsCount) {
        return 0;
    }

    int dp[valuesCount + 1][capacity + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= valuesCount; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weights[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = fmax(dp[i - 1][j],
                                dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 11; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return dp[valuesCount][capacity];
}

int select(int *values, const int valuesCount, int *weights,
           const int weightsCount, const int capacity) {
    if (values == NULL || weights == NULL || valuesCount != weightsCount) {
        return 0;
    }

    int dp[capacity + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= valuesCount; i++) {
        for (int j = capacity; j > 0; j--) {
            if (weights[i - 1] > j) {
                // dp[j] = dp[j]; 直接continue
                continue;
            }
            dp[j] = fmax(dp[j - 1], dp[j - weights[i - 1]] + values[i - 1]);
        }

        // for (int i = 0; i <= capacity; i++) {
        //     printf("%d ", dp[i]);
        // }
        // printf("\n");
    }

    return dp[capacity];
}
