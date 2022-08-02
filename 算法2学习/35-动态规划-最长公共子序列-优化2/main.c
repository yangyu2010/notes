#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestCommonSubsequence(char *text1, char *text2);

int main() {
    // char *text1 = "abcde";
    // char *text2 = "acde";

    char *text1 = "acde";
    char *text2 = "abcde";

    int count = longestCommonSubsequence(text1, text2);
    printf("%d", count);
    return 0;
}

// 用一维数组来
// int longestCommonSubsequence(char *text1, char *text2) {
//     int len1 = strlen(text1);
//     int len2 = strlen(text2);
//     if (text1 == NULL || len1 == 0 || text2 == NULL || len2 == 0) {
//         return 0;
//     }

//     int dp[len2 + 1];
//     /* void *memset(void *b, int c, size_t len) */
//     memset(dp, 0, sizeof(dp));

//     for (int i = 1; i <= len1; i++) {
//         int current = 0;
//         for (int j = 1; j <= len2; j++) {
//             int leftTop = current;
//             current = dp[j];
//             if (text1[i - 1] == text2[j - 1]) {
//                 dp[j] = leftTop + 1;
//             } else {
//                 dp[j] = (dp[j - 1] > dp[j]) ? dp[j - 1] : dp[j];
//             }
//         }
//     }

//     return dp[len2];
// }

int longestCommonSubsequence(char *text1, char *text2) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    if (text1 == NULL || len1 == 0 || text2 == NULL || len2 == 0) {
        return 0;
    }

    char *rows = text1;
    char *cols = text2;
    int row = len1;
    int col = len2;
    if (len1 < len2) {
        rows = text2;
        cols = text1;
        row = len2;
        col = len1;
    }

    int dp[col + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= row; i++) {
        int current = 0;
        for (int j = 1; j <= col; j++) {
            int leftTop = current;
            current = dp[j];
            if (rows[i - 1] == cols[j - 1]) {
                dp[j] = leftTop + 1;
            } else {
                dp[j] = (dp[j - 1] > dp[j]) ? dp[j - 1] : dp[j];
            }
        }
    }

    return dp[col];
}
