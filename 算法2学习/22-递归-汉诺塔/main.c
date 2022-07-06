#include <stdio.h>

void move(int n, char from, char to) {
    // printf("把%d号盘子 从%c移动到%c\n", n, from, to);
    printf("%d %c->%c\n", n, from, to);
}

void hanoi(int n, char from, char center, char to) {
    if (n <= 1) {
        move(n, from, to);
        return;
    }

    hanoi(n - 1, from, to, center);
    move(n, from, to);
    hanoi(n - 1, center, from, to);
}

int main() {
    hanoi(10, 'A', 'B', 'C');
    return 0;
}
