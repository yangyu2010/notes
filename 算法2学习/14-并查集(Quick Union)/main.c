#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
并查集
Quick Union
查找 O(logn)
合并 O(logn)
*/
struct FindUnion {
    int *parents;
    int capacity;

    int (*find)(struct FindUnion *, int);
    void (*union2)(struct FindUnion *, int, int);
    int (*isSame)(struct FindUnion *, int, int);
};

int find(struct FindUnion *fu, int v) {
    if (v < 0 || v >= fu->capacity) {
        return -1;
    }
    
    while (fu->parents[v] != v) {
        v = fu->parents[v];
    }
    return v;
}

void union2(struct FindUnion *fu, int v1, int v2) {
    int parent1 = fu->find(fu, v1);
    int parent2 = fu->find(fu, v2);
    if (parent1 == parent2) {
        return;
    }
    fu->parents[parent1] = parent2;

    // for (int i = 0; i < fu->capacity; i++) {
    //     if (fu->parents[i] == parent1) {
    //         fu->parents[i] = parent2;
    //     }
    // }
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
    for (int i = 0; i < capacity; i++) {
        fu->parents[i] = i;
    }
    return;
}

/* struct FindUnion 的析构函数 */
void _FindUnion(struct FindUnion *fu) { free(fu->parents); }

int main() {
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

    printf("%d", findUnion.isSame(&findUnion, 0, 1) == 1);
    printf("%d", findUnion.isSame(&findUnion, 0, 6) == 0);
    printf("%d", findUnion.isSame(&findUnion, 0, 7) == 0);
    printf("%d", findUnion.isSame(&findUnion, 1, 7) == 0);
    printf("%d", findUnion.isSame(&findUnion, 2, 7) == 0);
    printf("%d", findUnion.isSame(&findUnion, 3, 7) == 0);
    printf("%d", findUnion.isSame(&findUnion, 4, 7) == 0);
    printf("%d", findUnion.isSame(&findUnion, 5, 7) == 0);
    printf("%d", findUnion.isSame(&findUnion, 6, 7) == 1);
    printf("%d", findUnion.isSame(&findUnion, 8, 9) == 1);
    printf("%d", findUnion.isSame(&findUnion, 9, 10) == 1);
    printf("%d", findUnion.isSame(&findUnion, 11, 10) == 1);
    printf("%d", findUnion.isSame(&findUnion, 8, 11) == 1);
    printf("%d", findUnion.isSame(&findUnion, 6, 8) == 0);
    printf("%d", findUnion.isSame(&findUnion, 6, 9) == 0);
    printf("%d", findUnion.isSame(&findUnion, 6, 10) == 0);
    printf("%d", findUnion.isSame(&findUnion, 6, 11) == 0);

    findUnion.union2(&findUnion, 1, 6);

    printf("%d", findUnion.isSame(&findUnion, 0, 6) == 1);
    printf("%d", findUnion.isSame(&findUnion, 0, 7) == 1);
    printf("%d", findUnion.isSame(&findUnion, 1, 7) == 1);
    printf("%d", findUnion.isSame(&findUnion, 2, 7) == 1);
    printf("%d", findUnion.isSame(&findUnion, 3, 7) == 1);
    printf("%d", findUnion.isSame(&findUnion, 4, 7) == 1);
    printf("%d", findUnion.isSame(&findUnion, 5, 7) == 1);

    findUnion.union2(&findUnion, 7, 8);

    printf("%d", findUnion.isSame(&findUnion, 6, 8) == 1);
    printf("%d", findUnion.isSame(&findUnion, 6, 9) == 1);
    printf("%d", findUnion.isSame(&findUnion, 6, 10) == 1);
    printf("%d", findUnion.isSame(&findUnion, 6, 11) == 1);

    printf("%d", findUnion.isSame(&findUnion, 0, 8) == 1);
    printf("%d", findUnion.isSame(&findUnion, 0, 9) == 1);
    printf("%d", findUnion.isSame(&findUnion, 1, 10) == 1);
    printf("%d", findUnion.isSame(&findUnion, 2, 11) == 1);
    printf("%d", findUnion.isSame(&findUnion, 3, 10) == 1);
    printf("%d", findUnion.isSame(&findUnion, 4, 10) == 1);
    printf("%d", findUnion.isSame(&findUnion, 5, 11) == 1);

    _FindUnion(&findUnion);
    return 0;
}