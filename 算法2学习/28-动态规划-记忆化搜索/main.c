#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int coinChange(int *, int, int);
int coinChangeDP(int *coins, int coinsSize, int amount, int *dp);

int main() {
    // int coinsSize = 4;
    // int *coins = (int *)calloc(coinsSize, sizeof(int));
    // int array[4] = {1, 5, 10, 25};
    // for (int i = 0; i < coinsSize; i++) {
    //     coins[i] = array[i];
    // }

    // int count = coinChange(coins, coinsSize, 41);
    // printf("%d", count);

    int coinsSize = 1;
    int *coins = (int *)calloc(coinsSize, sizeof(int));
    int array[1] = {5};
    for (int i = 0; i < coinsSize; i++) {
        coins[i] = array[i];
    }

    int count = coinChange(coins, coinsSize, 5);
    printf("%d", count);

    return 0;
}

int coinChange(int *coins, int coinsSize, int amount) {
    if (amount == 0) {
        return 0;
    }

    int *dp = (int *)calloc(amount + 1, sizeof(int));
    /// 初始化默认值 比如dp[1] = 1; dp[5] = 1;
    for (int i = 0; i < coinsSize; i++) {
        int coin = coins[i];
        /// 必须比要兑换的数额少, 比如你要替换20元, 那dp[50] dp[100]不能是1
        /// dp[1] dp[5] dp[10]这些小的才是1
        if (coin <= amount) {
            dp[coin] = 1;
        }
    }

    return coinChangeDP(coins, coinsSize, amount, dp);
}

int coinChangeDP(int *coins, int coinsSize, int amount, int *dp) {
    if (amount < 0) {
        return INT_MAX;
    }
    if (dp[amount] == 0) {
        int min = INT_MAX;
        int find = 0;
        for (int i = 0; i < coinsSize; i++) {
            int coin = coinChangeDP(coins, coinsSize, amount - coins[i], dp);
            if (coin > 0 && coin < min) {
                min = coin;
                find = 1;
            }
        }
        if (find == 1) {
            dp[amount] = min + 1;
        } else {
            dp[amount] = -1;
        }
    }
    return dp[amount];
}