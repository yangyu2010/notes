#include <stdio.h>
#include <stdlib.h>

void placeQueen(int);
void place(int);
int valid(int, int);
void showPlace();

int main() {
    placeQueen(4);
    return 0;
}

/// 每一行的皇后放在上面位置
/// g_cols[0] = 1 就代表第0行 皇后在1的位置
/// g_cols[3] = 4 就代表第3行 皇后在4的位置
int *g_rows;

/// 当前列是否已经有皇后了
/// g_cols[0] = 1 第0列已经有皇后了
/// g_cols[3] = 1 第3列已经有皇后了
/// g_cols[4] = 0 第4列还没有皇后
int *g_cols;

/*
左上角到右下角的斜线 上是否有皇后了
0  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15

所在的条数是 row + col

第1条线 0
第2条线 1->4
第3条线 2->5->8
第4条线 3->6->9->12
第5条线 7->10->13
第6条线 11->14
第7条线 15
*/
int *g_leftTopToRightBottom;

/*
右上角到左下角的斜线 上是否有皇后了
0  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15

所在的条数是 row - col + 7

第1条线 3
第2条线 2->7
第3条线 1->6->11
第4条线 0->5->10->15
第5条线 4->9->14
第6条线 8->13
第7条线 12
*/
int *g_rightTopToLeftBottom;

/// 有几行几列
int g_size;
/// 最终有几种摆法
int g_queen_count;

void placeQueen(int size) {
    g_size = size;
    g_cols = (int *)calloc(size, sizeof(int));
    g_rows = (int *)calloc(size, sizeof(int));
    g_leftTopToRightBottom = (int *)calloc((size << 1) - 1, sizeof(int));
    g_rightTopToLeftBottom = (int *)calloc((size << 1) - 1, sizeof(int));
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
        /// 如果这一列有皇后了
        if (g_cols[col] == 1) {
            continue;
        }
        
        /// 判断两个斜线是否有皇后
        int leftTopIndex = row + col;
        int rightTopIndex = row - col + (g_size << 1) - 1;
        if (g_leftTopToRightBottom[leftTopIndex] == 1) {
            continue;
        }
        if (g_rightTopToLeftBottom[rightTopIndex] == 1) {
            continue;
        }

        /// 可以摆放就摆在这里 同时把状态标记一下
        g_cols[col] = 1;
        g_leftTopToRightBottom[leftTopIndex] = 1;
        g_rightTopToLeftBottom[rightTopIndex] = 1;
        g_rows[row] = col;

        /// 摆放下一行
        place(row + 1);

        /// 还原状态
        g_cols[col] = 0;
        g_leftTopToRightBottom[leftTopIndex] = 0;
        g_rightTopToLeftBottom[rightTopIndex] = 0;
    }
}

/// 每次摆放成功后 打印当前的摆放布局
void showPlace() {
    for (int row = 0; row < g_size; row++) {
        for (int col = 0; col < g_size; col++) {
            if (g_rows[row] == col) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("=======================\n");
}