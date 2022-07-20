#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int coinChange(int *, int, int);
int coinChangeDP(int *coins, int coinsSize, int amount, int *dp);

int main() {
    int coinsSize = 4;
    int *coins = (int *)calloc(coinsSize, sizeof(int));
    int array[4] = {1, 5, 10, 25};
    for (int i = 0; i < coinsSize; i++) {
        coins[i] = array[i];
    }

    int count = coinChange(coins, coinsSize, 41);
    printf("%d", count);

    // int coinsSize = 1;
    // int *coins = (int *)calloc(coinsSize, sizeof(int));
    // int array[1] = {2};
    // for (int i = 0; i < coinsSize; i++) {
    //     coins[i] = array[i];
    // }

    // int count = coinChange(coins, coinsSize, 1);
    // printf("%d", count);

    return 0;
}

int coinChange(int *coins, int coinsSize, int amount) {
    if (amount == 0) {
        return 0;
    }

    int *dp = (int *)calloc(amount + 1, sizeof(int));
    for (int i = 0; i < coinsSize; i++) {
        int coin = coins[i];
        dp[coin] = 1;
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