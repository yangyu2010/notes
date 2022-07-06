#include <stdio.h>
#include <stdlib.h>

void placeQueue(int);
void place(int);
int valid(int, int);
void showPlace();

int main() {
    placeQueue(8);
    return 0;
}

int *g_cols;
int g_size;
int g_queue_count;

void placeQueue(int size) {
    g_size = size;
    g_cols = (int *)calloc(size, sizeof(int));
    g_queue_count = 0;
    place(0);
    printf("g_queue_count = %d", g_queue_count);
}

/*
    0 0 0 0
    0 0 0 0
    0 0 0 0
    0 0 0 0
 */

void place(int row) {
    if (row == g_size) {
        g_queue_count += 1;
        showPlace();
        return;
    }

    for (int col = 0; col < g_size; col++) {
        if (valid(row, col) == 1) {
            g_cols[row] = col;
            place(row + 1);
        }
    }
}

int valid(int row, int col) {
    for (int i = 0; i < row; i++) {
        /// 当前列col 如果和之前的列相同 返回0
        if (g_cols[i] == col) {
            return 0;
        }

        /*
        如果是对角线 返回0
        0 3 0 0
        0 0 4 0
        0 6 0 5
        0 0 0 0
        3的位置是(0, 1)
        4的位置是(1, 2)
        5的位置是(2, 3)
        6的位置是(2, 1)

        求4的对角线?
        x1-x2 == y1-y2
        x1-x2 == -(y1-y2)
        */
        if ((row - i == col - g_cols[i]) || (row - i == -(col - g_cols[i]))) {
            return 0;
        }
    }
    return 1;
}

void showPlace() {
    for (int row = 0; row < g_size; row++) {
        for (int col = 0; col < g_size; col++) {
            if (g_cols[row] == col) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("=======================\n");
}