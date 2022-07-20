#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int coinChange(int *, int, int);
int coinChangeDP(int *coins, int coinsSize, int amount, int *dp);

int main() {
    // int coinsSize = 4;
    // int *coins = (int *)calloc(coinsSize, sizeof(int));
    // int array[4] = {1, 5, 20, 25};
    // for (int i = 0; i < coinsSize; i++) {
    //     coins[i] = array[i];
    // }

    // int count = coinChange(coins, coinsSize, 41);
    // printf("%d", count);

    int coinsSize = 1;
    int *coins = (int *)calloc(coinsSize, sizeof(int));
    int array[1] = {2};
    for (int i = 0; i < coinsSize; i++) {
        coins[i] = array[i];
    }

    int count = coinChange(coins, coinsSize, 1);
    printf("%d", count);

    return 0;
}

int coinChange(int *coins, int coinsSize, int amount) {
    if (coins == NULL || coinsSize == 0 || amount == 0) {
        return 0;
    }

    int *dp = (int *)calloc(amount + 1, sizeof(int));
    for (int i = 0; i < coinsSize; i++) {
        int coin = coins[i];
        if (coin <= amount) {
            dp[coin] = 1;
        }
    }

    for (int i = 1; i <= amount; i++) {
        if (dp[i] > 0) {
            continue;
        }

        int min = INT_MAX;
        //遍历货币列表 找出最少需要的个数
        for (int j = 0; j < coinsSize; j++) {
            int coin = coins[j];
            if (i > coin && dp[i - coin] > 0 && dp[i - coin] < min) {
                min = dp[i - coin];
            }
        }

        if (min == INT_MAX) {
            dp[i] = -1;
        } else {
            dp[i] = min + 1;
        }
    }

    return dp[amount];
}
