#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int longestCommonSubsequence(char *text1, char *text2);
int longestCommonSubsequenceSub(char *text1, int index1, char *text2,
                                int index2);

int main() {
    char *text1 = "ABCBDAB";
    char *text2 = "BDCABA";
    int count = longestCommonSubsequence(text1, text2);
    printf("%d", count);
    return 0;
}

int longestCommonSubsequence(char *text1, char *text2) {
    int length1 = sizeof(text1);
    int length2 = sizeof(text2);
    if (text1 == NULL || length1 == 0 || text2 == NULL || length2 == 0) {
        return 0;
    }
    return longestCommonSubsequenceSub(text1, length1, text2, length2);
}

int longestCommonSubsequenceSub(char *text1, int index1, char *text2,
                                int index2) {
    if (index1 == 0 || index2 == 0) {
        return 0;
    }

    if (text1[index1] == text2[index2]) {
        return longestCommonSubsequenceSub(text1, index1 - 1, text2,
                                           index2 - 1) + 1;
    } else {
        int count1 =
            longestCommonSubsequenceSub(text1, index1 - 1, text2, index2);
        int count2 =
            longestCommonSubsequenceSub(text1, index1, text2, index2 - 1);
        return count1 > count2 ? count1 : count2;
    }
}