#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
Next数组
aabaabaaa

a a b a a b a a a
0 1 2 3 4 5 6 7 8
-----------------
0 1 0 1 2 3 4 5 2

1.  默认0的位置

2.  i = 1 j = 0
    a == a
    相等时 next[i] = next[i - 1] + 1 (next[i - 1]也就是现在j的值)
    j++
    next[i] = j

3.  i = 2 j = 1
    b != a
    不相等时 j = next[j - 1] = 0;
    然后再比较
    还不相等
    next[i] = j = 0;

4.  i = 3 j = 0(上一步骤时把j==0了)
    a == a
    相等时 next[i] = next[i - 1] + 1 (next[i - 1]也就是现在j的值)
    j++
    next[i] = j = 1

5.  i = 4 j = 1
    a == a
    相等时 next[i] = next[i - 1] + 1 (next[i - 1]也就是现在j的值)
    j++
    next[i] = j = 2

6.  i = 5 j = 2
    b == b
    相等时 next[i] = next[i - 1] + 1 (next[i - 1]也就是现在j的值)
    j++
    next[i] = j = 3

7.  i = 6 j = 3
    a == a
    相等时 next[i] = next[i - 1] + 1 (next[i - 1]也就是现在j的值)
    j++
    next[i] = j = 4

8.  i = 7 j = 4
    a == a
    相等时 next[i] = next[i - 1] + 1 (next[i - 1]也就是现在j的值)
    j++
    next[i] = j = 5

9.  i = 8 j = 5
    a != b
    不相等时 j = next[j - 1] = next[4] = 2;
    然后再比较 
    此时 pattern[j] = pattern[2] = b
    pattern[i] = pattern[8] = a
    还不相等
    j = next[j - 1] = next[1] = 1;
    此时 pattern[j] = pattern[1] = a
    pattern[i] = pattern[8] = a
    相等了
    next[i] = j + 1 = 2;
*/

/**
text:    abxabcabcaby
pattern: abcaby

next数组: [0, 0, 0, 1, 2, 0]
abcaby
012345
------
000120

ti: text的索引下标
pi: pattern的索引下标

if (ti == pi) {
    ti++;
    pi++;
} else {
    pi = next[pi - 1]
    然后再次比较
    如果pi==0了 ti++
}

1. ti == 0, pi == 0 相等 
2. ti == 1, pi == 1 相等
3. ti == 2, pi == 2 
    不相等
    pi = next[pi - 1] = 0
    再次比较 ti == 2, pi == 0 不相等
4. ti == 3, pi == 0 相等
5. ti == 4, pi == 1 相等
6. ti == 5, pi == 2 相等
...
7. ti == 8, pi == 5 不相等
    pi = next[pi - 1] = next[4] = 2
    再次比较 ti == 8, pi == 2 相等
8. ti == 9, pi == 3 相等
...
 */

int indexOf(const char *, const char *);
int *prefixSuffixArray(const char *);

int main() {

    assert(indexOf("hello word", "or") == 7);
    assert(indexOf("hello word", "he") == 0);
    assert(indexOf("hello word", "d") == 9);
    assert(indexOf("hello word", "h") == 0);
    assert(indexOf("hello word", "rd") == 8);
    assert(indexOf("hello word", "") == -1);
    assert(indexOf("hello word", "hello word") == 0);

    assert(indexOf("hello word", "aaa") == -1);
    assert(indexOf("hello word", "heo") == -1);
    assert(indexOf("hello word", "hello word22") == -1);
    assert(indexOf("hello word", NULL) == -1);
    assert(indexOf(NULL, NULL) == -1);
    assert(indexOf(NULL, "or") == -1);
    assert(indexOf(NULL, "") == -1);
    assert(indexOf("", NULL) == -1);
    assert(indexOf("", "hello word") == -1);

    assert(indexOf("abxabcabcaby", "abcaby") == 6);
    assert(indexOf("abxabcabcaby", "abcab") == 3);
    assert(indexOf("abxabcabcaby", "abcabc") == 3);

    const char *text = "abxabcabcaby";
    const char *pattern = "abcaby";
    int *arr = prefixSuffixArray(pattern);
    for (size_t i = 0; i < strlen(pattern); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int index = indexOf(text, pattern);
    printf("%d", index);

    return 0;
}

int indexOf(const char *text, const char *pattern) {
    if (text == NULL || pattern == NULL) {
        return -1;
    }

    size_t tlen = strlen(text);
    size_t plen = strlen(pattern);

    if (tlen == 0 || plen == 0 || plen > tlen) {
        return -1;
    }
    int *arr = prefixSuffixArray(pattern);
    int i = 0, j = 0;
    while (j < plen && i < tlen) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        } else {
            if (j > 0) {
                j = arr[j - 1];
            } else {
                i++;
            }
        }
    }

    if (j == plen){
        return i - j;
    }
    
    free(arr);
    return -1;
}

int *prefixSuffixArray(const char *pattern) {
    int j = 0;
    size_t plen = strlen(pattern);
    int *arr = (int *)calloc(plen, sizeof(size_t));
    arr[0] = 0;
    for (size_t i = 1; i < plen; i++) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = arr[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            ++j;
        }
        arr[i] = j;
    }
    return arr;
}