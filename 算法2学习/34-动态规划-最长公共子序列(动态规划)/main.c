#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestCommonSubsequence(char *text1, char *text2);

// int  main()
// {
//      int  **p;  //定义二维指针。
//      int  m, n; //行数和列数。
//      int  i,j;

//      scanf ( "%d%d" , &m, &n);  //输入行数和列数。
//      if (m <= 0 || n <= 0)  return  -1;  //行数或列数非法。

//      p = ( int  **)  malloc ( sizeof ( int  *) *m); //申请一组一维指针空间。
//      for (i = 0; i < m; i ++)
//          p[i] = ( int  *) malloc ( sizeof ( int ) * n);
//          //对于每个一维指针，申请一行数据的空间。

//      for (i = 0; i < m; i ++)
//          for (j = 0; j < n; j ++)
//              scanf ( "%d" ,&p[i][j]);
//              //输入第i行第j列的数据。其中&p[i][j]也可以写作p[i]+j或者是
//              *(p+i) + j. 功能相同。

//      printf ( "输入的数组为%d行%d列：\n" , m, n);
//      for (i = 0; i < m; i ++)
//      {
//          for (j = 0; j < n; j ++) //这个循环可以输出一行元素。
//              printf ( "%d " , p[i][j]); //输出i行j列的元素。
//          printf ( "\n" ); //每行输入结束加换行符。
//      }

//      //释放内存
//      for (i = 0; i < m; i ++)
//          free (p[i]);
//      free (p);

//      return  0;
// }

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

    /**
    假设 dp(i, j) 是【nums1 前 i 个元素】与【nums2 前 j
    个元素】的最长公共子序列长度 dp(i, 0)、dp(0, j) 初始值均为 0

    nums1[i – 1] nums2[j – 1]是第i, j位
    如果 nums1[i – 1] = nums2[j – 1]，那么 dp(i, j) = dp(i – 1, j – 1) + 1
    如果 nums1[i – 1] ≠ nums2[j – 1]，那么 dp(i, j) = max { dp(i – 1, j), dp(i, j – 1) }
    */
    int dp[len1 + 1][len2 + 1];
    /* void *memset(void *b, int c, size_t len) */
    memset(dp, 0, sizeof(dp));

    // for (int i = 0; i < len1 + 1; i++) {
    //     dp[i][0] = 0;
    // }
    // for (int i = 0; i < len2 + 1; i++) {
    //     dp[0][i] = 0;
    // }

    // int **dp = (int **)calloc(len1 + 1, sizeof(int*));
    // for (int i = 0; i < len1 + 1; i++) {
    //     dp[i] = (int *)calloc(len2 + 1, sizeof(int));
    // }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] =
                    (dp[i][j - 1] > dp[i - 1][j]) ? dp[i][j - 1] : dp[i - 1][j];
            }
        }
    }

    return dp[len1][len2];
}
