#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sum(int n) {
    if (n <= 1) {
        return n;
    }
    return n + sum(n - 1);
}

// 1 1 2 3 5 8 13 21 34
int fib(int index) {
    if (index <= 1) {
        return 1;
    }
    return fib(index - 1) + fib(index - 2);
}

int fib1(int index, int *array) {
    if (array[index] == 0) {
        array[index] = fib1(index - 1, array) + fib1(index - 2, array);
    }
    return array[index];
}

void test1() {
    int s = sum(100);
    printf("%d", s);
}

void test2() {
    int size = 30;
    int f = fib(size - 1);
    printf("%d", f);
}

void test3() {
    int size = 30;
    int *array = (int *)calloc(size, sizeof(int));
    array[0] = 1;
    array[1] = 1;
    int f = fib1(size - 1, array);
    printf("%d", f);
}

void test4() {
    int size = 30;
    int *array = (int *)calloc(size, sizeof(int));
    array[0] = 1;
    array[1] = 1;
    for (int i = 2; i < size; i++) {
        array[i] = array[i - 1] + array[i - 2];
    }

    printf("\n%d", array[size - 1]);
}

/*
i & 1 == i % 2

0 % 2 = 0
1 % 2 = 1
2 % 2 = 0
3 % 2 = 1
4 % 2 = 0
5 % 2 = 1

0 0b0000
1 0b0001
2 0b0010
3 0b0011
4 0b0100
5 0b0101

*/
void test5() {
    int size = 30;
    int *array = (int *)calloc(2, sizeof(int));
    array[0] = 1;
    array[1] = 1;
    for (int i = 2; i < size; i++) {
        array[i & 1] = array[(i - 1) & 1] + array[(i - 2) & 1];
    }

    printf("\n%d", array[(size - 1) & 1]);
}

void test6() {
    int size = 30;
    int first = 1;
    int second = 1;

    // 2 3
    // 5 8

    for (int i = 2; i <= (size >> 1); i++) {
        first = first + second;
        second = first + second;
    }

    printf("%d\n", first);
    printf("%d\n", second);
}

void test7() {
    int size = 30;

    double c = sqrt(5);
    int fib = (pow((1 + c) / 2, size) - pow((1 - c) / 2, size)) / c;

    printf("%d\n", fib);
}

int main() {

    time_t c_start, t_start, c_end, t_end;
    c_start = clock();    //!< 单位为ms
    t_start = time(NULL); //!< 单位为s

    test7();

    c_end = clock();
    t_end = time(NULL);
    printf("\nThe sorting used %f ms by clock()\n",
           difftime(c_end, c_start) / CLOCKS_PER_SEC * 1000);
    printf("The sorting used %f s by time()\n", difftime(t_end, t_start));

    return 0;
}
