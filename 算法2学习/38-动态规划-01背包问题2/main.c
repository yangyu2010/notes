#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int select(int *, int, int *, int, int);

/**
0-1背包 – 恰好装满

有 n 件物品和一个最大承重为 W 的背包，每件物品的重量是 𝑤i、价值是 𝑣i
在保证总重量恰好等于 W 的前提下，选择某些物品装入背包，背包的最大总价值是多少?
注意:每个物品只有 1 件，也就是每个物品只能选择 0 件或者 1 件

dp(i, j) 初始状态调整
dp(i, 0) = 0，总重量恰好为 0，最大总价值必然也为 0
dp(0, j) = –∞(负无穷)，j ≥ 1，负数在这里代表无法恰好装满
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

int select(int *values, const int valuesCount, int *weights,
           const int weightsCount, const int capacity) {
    if (values == NULL || weights == NULL || valuesCount != weightsCount) {
        return 0;
    }

    int dp[capacity + 1];
    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= capacity; j++) {
        dp[j] = INT_MIN;
    }

    for (int i = 1; i <= valuesCount; i++) {
        for (int j = capacity; j > 0; j--) {
            if (weights[i - 1] > j) {
                // dp[j] = dp[j]; 直接continue
                continue;
            }
            dp[j] = fmax(dp[j], dp[j - weights[i - 1]] + values[i - 1]);
        }

        for (int i = 0; i <= capacity; i++) {
            printf("%d ", dp[i]);
        }
        printf("\n");
    }

    return dp[capacity] > 0 ? dp[capacity] : -1;
}
