#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestCommonSubsequence(char *text1, char *text2);

int main() {
    char *text1 = "abcde";
    char *text2 = "ace";

    int count = longestCommonSubsequence(text1, text2);
    printf("%d", count);
    return 0;
}

int longestCommonSubsequence(char *text1, char *text2) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    if (text1 == NULL || len1 == 0 || text2 == NULL || len2 == 0) {
        return 0;
    }

    /// 使用滚动数组 只记录2行 因为每一次查询只用到上一行的数据
    int dp[2][len2 + 1];
    /* void *memset(void *b, int c, size_t len) */
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int row = i & 1;
            int prevRow = (i - 1) & 1;
            if (text1[i - 1] == text2[j - 1]) {
                dp[row][j] = dp[prevRow][j - 1] + 1;
            } else {
                dp[row][j] = (dp[row][j - 1] > dp[prevRow][j]) ? dp[row][j - 1]
                                                               : dp[prevRow][j];
            }
        }
    }

    return dp[len1 & 1][len2];
}
