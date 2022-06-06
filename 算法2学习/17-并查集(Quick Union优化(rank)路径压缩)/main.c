#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
并查集 基于rank(树高度)的优化 路径压缩 Path Compression
Quick Union
查找 O(logn)
合并 O(logn)

The sorting used 11.049000 ms by clock()
The sorting used 0.000000 s by time()
*/
struct FindUnion {
    int *parents;
    int capacity;
    int *ranks;

    int (*find)(struct FindUnion *, int);
    void (*union2)(struct FindUnion *, int, int);
    int (*isSame)(struct FindUnion *, int, int);
};

int find(struct FindUnion *fu, int v) {
    if (v < 0 || v >= fu->capacity) {
        return -1;
    }

    /*
    5
    4
    3
    2
    1
    假如要找1的根节点(1->2->3->4->5)
    把这条链路上所有的节点都指向根接口
    find(fu, fu->parents[v])是找到根节点
    */
    if (fu->parents[v] != v) {
        fu->parents[v] = find(fu, fu->parents[v]);
    }
    return fu->parents[v];
}

void union2(struct FindUnion *fu, int v1, int v2) {
    int parent1 = fu->find(fu, v1);
    int parent2 = fu->find(fu, v2);
    if (parent1 == parent2) {
        return;
    }
    // 如果parent1的节点数量大于parent2的节点数量
    // 就把parent2指向parent1
    // parent1的size增加
    if (fu->ranks[parent1] > fu->ranks[parent2]) {
        fu->parents[parent2] = parent1;
    } else if (fu->ranks[parent1] < fu->ranks[parent2]) {
        fu->parents[parent1] = parent2;
    } else {
        fu->parents[parent1] = parent2;
        fu->ranks[parent2] += 1;
    }
}

int isSame(struct FindUnion *fu, int v1, int v2) {
    int parent1 = fu->find(fu, v1);
    int parent2 = fu->find(fu, v2);
    if (parent1 == parent2) {
        return 1;
    } else {
        return 0;
    }
    // if (this->find(this, v1) == this->find(this, v2)) {
    //     return 1;
    // }
    // return 0;
}

/* struct FindUnion 的构造函数 */
void FindUnion(struct FindUnion *fu, int capacity) {
    fu->capacity = capacity;
    fu->find = find;
    fu->union2 = union2;
    fu->isSame = isSame;
    fu->parents = (int *)calloc(sizeof(int), capacity);
    fu->ranks = (int *)calloc(sizeof(int), capacity);
    for (int i = 0; i < capacity; i++) {
        fu->parents[i] = i;
        fu->ranks[i] = 1;
    }
    return;
}

/* struct FindUnion 的析构函数 */
void _FindUnion(struct FindUnion *fu) { free(fu->parents); }

void testFindUnion1() {
    struct FindUnion findUnion;
    FindUnion(&findUnion, 12);

    findUnion.union2(&findUnion, 0, 1);
    findUnion.union2(&findUnion, 0, 3);
    findUnion.union2(&findUnion, 0, 4);
    findUnion.union2(&findUnion, 2, 3);
    findUnion.union2(&findUnion, 2, 5);
    findUnion.union2(&findUnion, 3, 3);

    findUnion.union2(&findUnion, 6, 7);

    findUnion.union2(&findUnion, 8, 9);
    findUnion.union2(&findUnion, 8, 10);
    findUnion.union2(&findUnion, 9, 10);
    findUnion.union2(&findUnion, 9, 11);

    assert(findUnion.isSame(&findUnion, 0, 1) == 1);
    assert(findUnion.isSame(&findUnion, 0, 6) == 0);
    assert(findUnion.isSame(&findUnion, 0, 7) == 0);
    assert(findUnion.isSame(&findUnion, 1, 7) == 0);
    assert(findUnion.isSame(&findUnion, 2, 7) == 0);
    assert(findUnion.isSame(&findUnion, 3, 7) == 0);
    assert(findUnion.isSame(&findUnion, 4, 7) == 0);
    assert(findUnion.isSame(&findUnion, 5, 7) == 0);
    assert(findUnion.isSame(&findUnion, 6, 7) == 1);
    assert(findUnion.isSame(&findUnion, 8, 9) == 1);
    assert(findUnion.isSame(&findUnion, 9, 10) == 1);
    assert(findUnion.isSame(&findUnion, 11, 10) == 1);
    assert(findUnion.isSame(&findUnion, 8, 11) == 1);
    assert(findUnion.isSame(&findUnion, 6, 8) == 0);
    assert(findUnion.isSame(&findUnion, 6, 9) == 0);
    assert(findUnion.isSame(&findUnion, 6, 10) == 0);
    assert(findUnion.isSame(&findUnion, 6, 11) == 0);

    findUnion.union2(&findUnion, 1, 6);

    assert(findUnion.isSame(&findUnion, 0, 6) == 1);
    assert(findUnion.isSame(&findUnion, 0, 7) == 1);
    assert(findUnion.isSame(&findUnion, 1, 7) == 1);
    assert(findUnion.isSame(&findUnion, 2, 7) == 1);
    assert(findUnion.isSame(&findUnion, 3, 7) == 1);
    assert(findUnion.isSame(&findUnion, 4, 7) == 1);
    assert(findUnion.isSame(&findUnion, 5, 7) == 1);

    findUnion.union2(&findUnion, 7, 8);

    assert(findUnion.isSame(&findUnion, 6, 8) == 1);
    assert(findUnion.isSame(&findUnion, 6, 9) == 1);
    assert(findUnion.isSame(&findUnion, 6, 10) == 1);
    assert(findUnion.isSame(&findUnion, 6, 11) == 1);

    assert(findUnion.isSame(&findUnion, 0, 8) == 1);
    assert(findUnion.isSame(&findUnion, 0, 9) == 1);
    assert(findUnion.isSame(&findUnion, 1, 10) == 1);
    assert(findUnion.isSame(&findUnion, 2, 11) == 1);
    assert(findUnion.isSame(&findUnion, 3, 10) == 1);
    assert(findUnion.isSame(&findUnion, 4, 10) == 1);
    assert(findUnion.isSame(&findUnion, 5, 11) == 1);

    _FindUnion(&findUnion);
}

void testFindUnion2() {
    int size = 100000;
    struct FindUnion findUnion;
    FindUnion(&findUnion, size);

    time_t c_start, t_start, c_end, t_end;
    c_start = clock();    //!< 单位为ms
    t_start = time(NULL); //!< 单位为s

    for (int i = 0; i < size; i++) {
        findUnion.union2(&findUnion, random() % size, random() % size);
    }

    for (int i = 0; i < size; i++) {
        findUnion.isSame(&findUnion, random() % size, random() % size);
    }

    c_end = clock();
    t_end = time(NULL);
    printf("\nThe sorting used %f ms by clock()\n",
           difftime(c_end, c_start) / CLOCKS_PER_SEC * 1000);
    printf("The sorting used %f s by time()\n", difftime(t_end, t_start));

    _FindUnion(&findUnion);
}

int main() {
    testFindUnion1();
    testFindUnion2();

    return 0;
}