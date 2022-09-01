#include <assert.h>
#include <string.h>

int indexOf(const char *, const char *);

int main() {
    // const char *text = "hello word";
    // const char *pattern = "or";
    // int index = indexOf(text, pattern);
    // printf("%d", index);

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
    
    // ti表示每一轮对比首字符的位置
    // ti + pi表示这一次要对比的text中的字符
    for (size_t ti = 0; ti <= tlen - plen; ti++) {
        size_t pi = 0;
        for (; pi < plen; pi++) {
            if (text[ti + pi] != pattern[pi]) {
                break;
            }
        }

        if (pi == plen) {
            return ti;
        }
    }

    return -1;
}

int indexOf2(const char *text, const char *pattern) {
    // 判断空
    if (text == NULL || pattern == NULL) {
        return -1;
    }

    size_t tlen = strlen(text);
    size_t plen = strlen(pattern);

    // 判断pattern比text长度要小
    if (tlen == 0 || plen == 0 || plen > tlen) {
        return -1;
    }

    /**
    为什么是 ti - pi <= tmax
    而不是 ti <= tmax ???
    tmax = tlen - plen

    假设text pattern如下
    text    [1, 0, 0, 1, 0, 0, 1, 1, 1, 0]
    pattern [1, 1, 0, 0]

    tlen = 10
    plen = 4
    那么 tmax = 6 如果ti <= tmax 那么这种情况下ti就不能比较后面的了
    [1, 0, 0, 1, 0, 0, 1, 1, 1, 0]
                      [1, 1, 0, 0]

    我们想要的是当 新的一轮开始比较时 ti > tmax 时这种情况 不需要再比较了
    [1, 0, 0, 1, 0, 0, 1, 1, 1, 0]
                          [1, 1, 0, 0]
    ti – pi 是指每一轮比较中 text 首个比较字符的位置
     */
    int ti = 0, pi = 0, tmax = tlen - plen;
    while (pi < plen && (ti - pi) <= tmax) {
        if (text[ti] == pattern[pi]) {
            ti++;
            pi++;
        } else {
            ti = ti - pi + 1;
            pi = 0;
        }
    }

    return (pi == plen) ? (ti - pi) : -1;
}

/*
int indexOf2(const char *text, const char *pattern) {
    // 判断空
    if (text == NULL || pattern == NULL) {
        return -1;
    }

    size_t tlen = strlen(text);
    size_t plen = strlen(pattern);

    // 判断pattern比text长度要小
    if (tlen == 0 || plen == 0 || plen > tlen) {
        return -1;
    }

    int ti = 0, pi = 0;
    while (ti < tlen && pi < plen) {
        if (text[ti] == pattern[pi]) {
            ti++;
            pi++;
        } else {
            ti = ti - pi + 1;
            pi = 0;
        }
    }

    return (pi == plen) ? (ti - pi) : -1;
}
*/

/*
int indexOf(const char *text, const char *pattern) {
    // 判断空
    if (text == NULL || pattern == NULL) {
        return -1;
    }

    size_t tlen = strlen(text);
    size_t plen = strlen(pattern);

    // 判断pattern比text长度要小
    if (plen > tlen) {
        return -1;
    }

    for (size_t ti = 0; ti < tlen; ti++) {
        size_t pi = 0;
        for (; pi < plen; pi++) {
            if (text[ti] == pattern[pi]) {
                ti++;
                continue;
            } else {
                break;
            }
        }
        if (pi == plen) {
            return ti - pi;
        }
    }
    return -1;
}
*/