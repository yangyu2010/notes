#include <assert.h>
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

int fib2(int index, int *array) {
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
    int f = fib(40);
    printf("%d", f);
}

void test3() {
    int size = 30;
    int *array = (int *)calloc(size, sizeof(int));
    array[0] = 1;
    array[1] = 1;
    int f = fib1(size, array);
    printf("%d", f);
}


int main() {

    time_t c_start, t_start, c_end, t_end;
    c_start = clock();    //!< 单位为ms
    t_start = time(NULL); //!< 单位为s

    test3();

    c_end = clock();
    t_end = time(NULL);
    printf("\nThe sorting used %f ms by clock()\n",
           difftime(c_end, c_start) / CLOCKS_PER_SEC * 1000);
    printf("The sorting used %f s by time()\n", difftime(t_end, t_start));

    return 0;
}
