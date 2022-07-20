#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
https://leetcode.cn/problems/coin-change/
假设有 25 分、10 分、5 分、1 分的硬币，现要找给客户 41
分的零钱，如何办到硬币个数最少?

假设有 25 分、20 分、5 分、1 分的硬币，现要找给客户 41
分的零钱，如何办到硬币个数最少?

dp(41)
第一次要在coins(25, 10, 5, 1)中取一枚
那问题就是在 dp(41 - 25) dp(41 - 10) dp(41 - 5) dp(41 - 1)中找出最少的
dp(41 - 25) + 1
dp(41 - 10) + 1
dp(41 - 5) + 1
dp(41 - 1) + 1
*/

/**
int coinChange(int);
int coinChange2(int);

int main() {
    int count = coinChange2(19);
    printf("%d", count);
    return 0;
}

int coinChange2(int amount) {
    if (amount <= 0) {
        return INT_MAX;
    }
    if (amount == 25 || amount == 10 || amount == 5 || amount == 1) {
        return 1;
    }
    int min = INT_MAX;
    int count1 = coinChange2(amount - 1);
    int count2 = coinChange2(amount - 5);
    int count3 = coinChange2(amount - 10);
    int count4 = coinChange2(amount - 25);
    if (count1 < min) {
        min = count1;
        printf("1 ");
    }
    if (count2 < min) {
        min = count2;
        printf("5 ");
    }
    if (count3 < min) {
        min = count3;
        printf("10 ");
    }
    if (count4 < min) {
        min = count4;
        printf("20 ");
    }
    // printf("\n");
    // printf(" %d", min);
    printf("%d ", amount);
    // printf("%d", min+1);
    printf("\n");
    return min + 1;
}

int coinChange(int amount) {
    if (amount <= 0) {
        return INT_MAX;
    }
    if (amount == 25 || amount == 10 || amount == 5 || amount == 1) {
        return 1;
    }
    int min = INT_MAX;
    if (amount > 1) {
        int count = coinChange(amount - 1);
        if (count < min) {
            min = count;
        }
    }
    if (amount > 5) {
        int count = coinChange(amount - 5);
        if (count < min) {
            min = count;
        }
    }
    if (amount > 10) {
        int count = coinChange(amount - 10);
        if (count < min) {
            min = count;
        }
    }
    if (amount > 25) {
        int count = coinChange(amount - 25);
        if (count < min) {
            min = count;
        }
    }

    return min + 1;
}
*/

int coinChange(int *, int, int);

int main() {
    // int coinsSize = 4;
    // int *coins = (int *)calloc(coinsSize, sizeof(int));
    // int array[4] = {1, 5, 10, 25};
    // for (int i = 0; i < coinsSize; i++) {
    //     coins[i] = array[i];
    // }

    // int count = coinChange(coins, coinsSize, 19);
    // printf("%d", count);

    int coinsSize = 3;
    int *coins = (int *)calloc(coinsSize, sizeof(int));
    int array[3] = {1, 2, 5};
    // int array[1] = {2};
    for (int i = 0; i < coinsSize; i++) {
        coins[i] = array[i];
    }

    int count = coinChange(coins, coinsSize, 100);
    printf("%d", count);

    return 0;
}


int coinChange(int *coins, int coinsSize, int amount) {
    if (amount == 0) {
        return 0;
    }

    if (amount < 0) {
        return INT_MAX;
    }

    for (int i = 0; i < coinsSize; i++) {
        if (amount == coins[i]) {
            return 1;
        }
    }

    int min = INT_MAX;
    int find = 0;
    for (int i = 0; i < coinsSize; i++) {
        int coin = coinChange(coins, coinsSize, amount - coins[i]);
        if (coin > 0 && coin < min) {
            min = coin;
            find = 1;
        }
    }

    return find == 0 ? - 1 : (min + 1);
}