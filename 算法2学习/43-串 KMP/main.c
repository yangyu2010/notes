#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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