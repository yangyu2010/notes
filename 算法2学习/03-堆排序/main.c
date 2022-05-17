#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // pulls in declaration of malloc, free
#include <string.h> // pulls in declaration for strlen.

/*
 创建一个堆
 */

typedef struct _heap {
    int *heap;    //指向存放堆对数组
    int capacity; //堆的大小
    int size;     //堆目前的元素
} heap;

heap *createHeap(int capacity) {
    heap *h = (heap *)malloc(sizeof(heap));
    h->heap = (int *)malloc(sizeof(int) * (capacity));
    // free(h->heap);
    // free(h);
    h->capacity = capacity;
    h->size = 0;
    return h;
}

// 打印堆中的元素
void dump(heap *h) {
    // int count = h->size;
    int size = h->size;
    int *heap = h->heap;
    for (int i = 0; i < size; i++) {
        printf("%d_", heap[i]);
    }

    printf("\n");
}

// 交换数组的元素arr[idx1]和arr[idx2]
void swap(int *arr, int idx1, int idx2) {
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

void siftUp(heap *h, int index) {
    int *heap = h->heap;
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex]) {
            int temp = heap[index];
            heap[index] = heap[parentIndex];
            heap[parentIndex] = temp;

            index = parentIndex;
        } else {
            break;
        }
    }
}

// 添加元素
void addElement(heap *h, int e) {
    // 判断堆的size
    if (h->size >= h->capacity) {
        return;
    }

    // 在数组最后加入新的元素
    int *heap = h->heap;
    int count = h->size;
    heap[count++] = e;
    h->size = count;

    siftUp(h, count - 1);

    /*
        // 刚添加的数据的位置
        int childIndex = count - 1;
        // 父节点的位置
        int parentIndex = (childIndex - 1) / 2;
        while ((parentIndex >= 0) && (heap[childIndex] > heap[parentIndex]))
        {
            swap(heap, childIndex, parentIndex);
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    */
}

void removeElement(heap *h) {

    if (h->size < 1) {
        return;
    }

    //用最后一个元素替代第一个元素
    // int size = h->size;
    int *heap = h->heap;
    heap[0] = heap[--h->size];
}

int main() {
    heap *h = createHeap(100);

    // 21_19_6_12_10_2_5_1_9
    /*
                21
            19        6
        12     10   2   5
    1      9
    */

    /*
        2, 1, 10, 21


    */
    // int arr[] = {2, 1, 10, 21};
    // int arr[] = {2, 1, 10, 21, 19, 6, 5, 12, 9};
    int arr[] = {13, 76, 22, 56, 78, 26, 91, 59, 33, 62,
                 63, 93, 68, 39, 65, 86, 41, 88, 20};
    // 93_88_91_86_63_78_65_59_76_56_62_22_68_26_39_13_41_33_20_
    int i;
    for (i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
        addElement(h, arr[i]);
    }
    dump(h);

    return 0;
}

int main1() {
    printf("%d\n", 0 >> 1);
    printf("%d\n", 1 >> 1);

    printf("%d\n", 2 >> 1);
    printf("%d\n", 3 >> 1);

    printf("%d\n", 4 >> 1);
    printf("%d\n", 5 >> 1);

    printf("%d\n", 6 >> 1);
    printf("%d\n", 7 >> 1);

    printf("%d\n", 8 >> 1);
    printf("%d\n", 9 >> 1);

    // printf("%d\n", 0 / 2);
    // printf("%d\n", 1 / 2);

    // printf("%d\n", 2 / 2);
    // printf("%d\n", 3 / 2);

    // printf("%d\n", 4 / 2);
    // printf("%d\n", 5 / 2);

    // printf("%d\n", 6 / 2);
    // printf("%d\n", 7 / 2);

    // printf("%d\n", 8 / 2);
    // printf("%d\n", 9 / 2);

    return 0;
}