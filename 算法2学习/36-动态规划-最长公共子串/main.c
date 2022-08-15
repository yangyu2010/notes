#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
最长公共子串(Longest Common Substring)
子串是连续的子序列
◼ 求两个字符串的最长公共子串长度
ABCBA 和 BABCA 的最长公共子串是 ABC，长度为 3

i i ∈ [1, str1.length]
j ∈ [1, str2.length]

假设 dp(i, j) 是以 str1[i – 1]、str2[j – 1] 结尾的最长公共子串长度

dp[1][1]是第str1[0], str2[0]结尾的最长公共子串长度(A, B) 0
dp[1][2]是第str1[0], str2[1]结尾的最长公共子串长度(A, BA) 1(A)
dp[2][2]是第str1[1], str2[1]结尾的最长公共子串长度(AB, BA) 0
dp[2][3]是第str1[1], str2[2]结尾的最长公共子串长度(AB, BAB) 2(AB)
dp[3][3]是第str1[2], str2[2]结尾的最长公共子串长度(ABC, BAB) 0
dp[3][4]是第str1[2], str2[3]结尾的最长公共子串长度(ABC, BABC) 3(ABC)
dp[4][4]是第str1[3], str2[3]结尾的最长公共子串长度(ABCB, BABC) 0
dp[5][5]是第str1[4], str2[4]结尾的最长公共子串长度(ABCBA, BABCA) 1(A)

if (str1[i] == str2[j]) {
    dp(i, j) = dp(i - 1, j - 1) + 1;
} else {
    dp(i, j) = 0;
}
*/

int longestCommonSubstring(char *text1, char *text2);

int main() {
    char *text1 = "abcd";
    char *text2 = "dabc";

    // char *text1 = "acde";
    // char *text2 = "abcde";

    // char *text1 = "ABCBA";
    // char *text2 = "BABCA";

    int count = longestCommonSubstring(text1, text2);
    printf("%d", count);
    return 0;
}

int longestCommonSubstring1(char *text1, char *text2) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    if (text1 == NULL || len1 == 0 || text2 == NULL || len2 == 0) {
        return 0;
    }
    int dp[len1 + 1][len2 + 1];
    memset(dp, 0, sizeof(dp));
    int max = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                printf("%c %c %d %d %d\n", text1[i - 1], text2[j - 1], i, j,
                       dp[i][j]);
                if (dp[i][j] > max) {
                    max = dp[i][j];
                }
            }
        }
    }

    return max;
}

int longestCommonSubstring2(char *text1, char *text2) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    if (text1 == NULL || len1 == 0 || text2 == NULL || len2 == 0) {
        return 0;
    }
    //根据行大小来定义dp数组
    int dp[len2 + 1];
    memset(dp, 0, sizeof(dp));
    int max = 0;

    for (int i = 1; i <= len1; i++) { // 行
        int current = 0;
        for (int j = 1; j <= len2; j++) { // 列
            int leftTop = current;
            current = dp[j];
            if (text1[i - 1] == text2[j - 1]) {
                dp[j] = leftTop + 1;
                printf("%c %c %d %d %d\n", text1[i - 1], text2[j - 1], i, j,
                       dp[j]);
                if (dp[j] > max) {
                    max = dp[j];
                }
            }
        }
    }

    return max;
}

int longestCommonSubstring3(char *text1, char *text2) {
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

    //根据行大小来定义dp数组
    int dp[col + 1];
    memset(dp, 0, sizeof(dp));
    int max = 0;

    for (int i = 1; i <= row; i++) { // 行
        int current = 0;
        for (int j = 1; j <= col; j++) { // 列
            int leftTop = current;
            current = dp[j];
            if (rows[i - 1] == cols[j - 1]) {
                dp[j] = leftTop + 1;
                printf("%c %c %d %d %d\n", rows[i - 1], cols[j - 1], i, j,
                       dp[j]);
                if (dp[j] > max) {
                    max = dp[j];
                }
            }
        }
    }

    return max;
}

int longestCommonSubstring(char *text1, char *text2) {
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

    //根据行大小来定义dp数组
    int dp[col + 1];
    memset(dp, 0, sizeof(dp));
    int max = 0;

    for (int i = 1; i <= row; i++) { // 行
        for (int j = col; j >= 1; j--) { // 从右边开始遍历
            if (rows[i - 1] == cols[j - 1]) {
                dp[j] = dp[j - 1] + 1;
                printf("%c %c %d %d %d\n", rows[i - 1], cols[j - 1], i, j,
                       dp[j]);
            } else {
                dp[j] = 0;
            }
            if (dp[j] > max) {
                max = dp[j];
            }
        }
    }

    return max;
}
