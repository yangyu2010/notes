#include <stdio.h>
#include <stdlib.h>

void placeQueen(int);
void place(int);
int valid(int, int);
void showPlace();

int main() {
    placeQueen(8);
    return 0;
}

/// 每一行的皇后放在上面位置
/// g_cols[0] = 1 就代表第0行 皇后在1的位置
/// g_cols[3] = 4 就代表第3行 皇后在4的位置
int *g_cols;
/// 有几行几列
int g_size;
/// 最终有几种摆法
int g_queen_count;

void placeQueen(int size) {
    g_size = size;
    g_cols = (int *)calloc(size, sizeof(int));
    g_queen_count = 0;
    place(0);
    printf("g_queen_count = %d", g_queen_count);
}

/// 摆放第几行
void place(int row) {
    if (row == g_size) {
        g_queen_count += 1;
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

/// [row, col]这个位置是否可以摆放
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

/// 每次摆放成功后 打印当前的摆放布局
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