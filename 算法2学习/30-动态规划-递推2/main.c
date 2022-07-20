#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int coinChange(int *, int, int);
int coinChangeDP(int *coins, int coinsSize, int amount, int *dp);

int main() {
    int coinsSize = 4;
    int *coins = (int *)calloc(coinsSize, sizeof(int));
    int array[4] = {5, 10, 20, 25};
    for (int i = 0; i < coinsSize; i++) {
        coins[i] = array[i];
    }

    int count = coinChange(coins, coinsSize, 3);
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
    if (coins == NULL || coinsSize == 0 || amount == 0) {
        return 0;
    }

    int *dp = (int *)calloc(amount + 1, sizeof(int));

    for (int i = 1; i <= amount; i++) {
        int min = INT_MAX;
        // 遍历货币列表 找出最少需要的个数
        /**
        货币 1 5 10 20
        查找 41

        i == 1
            这里从1开始 1 >= 1(满足) dp[1 - 1] = 0 >= 0(满足) dp[1 - 1] = 0 <
        min(满足) 所以 min = dp[0] = 0 了 后面 dp[i] = min + 1 所以 dp[1] = 1

        i == 2
            2 >= 1(满足) dp[2 - 1] = 1 >= 0(满足) dp[2 - 1] = 1 < min(满足)
            后面 dp[i] = min + 1 所以 dp[2] = 2

        同理得出3 4

        i == 5
            j == 0 时 coin == 1
                5 >= 1(满足) dp[5 - 1] = 1 >= 0(满足) dp[5 - 1] = 1 < min(满足)
                min = dp[5 - 1] = dp[4] = 4
            j == 1 时 coin == 5
                5 >= 5(满足) dp[5 - 5] = 0 >= 0(满足) dp[5 - 5] = 0 <
        min(4)(满足) min = dp[5 - 5] = dp[0] = 0 j == 2 或者 j == 3 i >= coin
        不满足 不会更改 min 的值了 后面 dp[i] = min + 1 所以 dp[5] = 1
        */
        for (int j = 0; j < coinsSize; j++) {
            int coin = coins[j];
            if (i >= coin && dp[i - coin] >= 0 && dp[i - coin] < min) {
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
