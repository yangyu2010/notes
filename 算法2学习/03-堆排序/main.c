#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // pulls in declaration of malloc, free
#include <string.h> // pulls in declaration for strlen.
#include <time.h>
/*
 创建一个堆
 */

typedef struct _heap {
    int *array;   //指向存放堆对数组
    int capacity; //堆的大小
    int size;     //堆目前的元素
} heap;

heap *createHeap(int capacity) {
    heap *h = (heap *)malloc(sizeof(heap));
    h->array = (int *)malloc(sizeof(int) * (capacity));
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
    int *array = h->array;
    for (int i = 0; i < size; i++) {
        printf("%d_", array[i]);
    }

    printf("\n");
}

// 交换数组的元素arr[idx1]和arr[idx2]
void swap(int *arr, int idx1, int idx2) {
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

// 上滤
void siftUp(heap *h, int index) {
    if (index >= h->size) {
        return;
    }

    /*
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
    */

    int *array = h->array;
    int element = array[index];

    /*
    每次把父节点的数据放下来
    不做交换
    到最后确定位置后再把新加的数据放入
    */
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (element > array[parentIndex]) {
            array[index] = array[parentIndex];
            index = parentIndex;
        } else {
            break;
        }
    }

    array[index] = element;
}

// 下滤
void siftDown(heap *h, int index) {
    // while (index < 第一个叶子节点的位置)
    // while (index < 非叶子节点的数量)
    // int *array = h->heap;

    int size = h->size;
    int half = size >> 1;

    int *heap = h->array;
    int element = heap[index];

    while (index < half) {
        // 非叶子节点的子节点数量情况
        // 只有左子节点
        // 有左右子节点

        // 取出左子节点的下标和数据
        int leftChildIndex = 2 * index + 1;
        int leftChildElement = heap[leftChildIndex];

        int childIndex = leftChildIndex;
        int childElement = leftChildElement;

        // 取出右子节点的下标
        // 判断是否有下标 同时和左子节点比较大小 取出大的
        int rightChildIndex = leftChildIndex + 1;
        if (rightChildIndex < size &&
            leftChildElement < heap[rightChildIndex]) {
            childIndex = rightChildIndex;
            childElement = heap[rightChildIndex];
        }

        if (childElement > element) {
            heap[index] = childElement;
            index = childIndex;
        } else {
            break;
        }
    }

    heap[index] = element;
}

// 添加元素
void addElement(heap *h, int e) {
    // 判断堆的size
    if (h->size >= h->capacity) {
        return;
    }

    // 在数组最后加入新的元素
    int *array = h->array;
    int count = h->size;
    array[count++] = e;
    h->size = count;

    siftUp(h, count - 1);

    /*
        // 刚添加的数据的位置
        int childIndex = count - 1;
        // 父节点的位置
        int parentIndex = (childIndex - 1) / 2;
        while ((parentIndex >= 0) && (array[childIndex] > array[parentIndex]))
        {
            swap(heap, childIndex, parentIndex);
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    */
}

// 移出堆顶元素
void removelement(heap *h) {

    if (h->size < 1) {
        return;
    }

    //用最后一个元素替代第一个元素
    // int size = h->size;
    int *array = h->array;
    array[0] = array[--h->size];
    array[h->size] = NULL;

    siftDown(h, 0);
}

/**
The sorting used 20.546000 ms by clock()
The sorting used 0.000000 s by time()
 */
int main() {
    // heap *h = createHeap(100);
    // int *array = h->array;
    // // int arr[] = {2, 1, 10, 21, 19, 6, 5, 12, 9};
    // int arr[] = {13, 76, 22, 56, 78, 26, 91, 59, 33, 62,
    //              63, 93, 68, 39, 65, 86, 41, 88, 20};
    // int length = (sizeof(arr) / sizeof(int));
    // for (int i = 0; i < length; i++) {
    //     h->size++;
    //     array[i] = arr[i];
    // }
    // for (int i = 0; i < length; i++) {
    //     printf("%d,", array[i]);
    // }

    int length = 100000;
    heap *h = createHeap(length);
    int *array = h->array;
    int *arr = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        arr[i] = random() % 10000;
    }
    for (int i = 0; i < length; i++) {
        h->size++;
        array[i] = arr[i];
    }
    for (int i = 0; i < length; i++) {
        printf("%d,", array[i]);
    }

    time_t c_start, t_start, c_end, t_end;
    c_start = clock();    //!< 单位为ms
    t_start = time(NULL); //!< 单位为s

    //================上面是准备数据代码 下面才是真正排序的代码================
    for (int i = length / 2 - 1; i >= 0; i--) {
        siftDown(h, i);
    }
    while (h->size > 1) {
        int temp = array[0];
        // array[0] = array[--length];
        array[0] = array[h->size - 1];
        array[h->size - 1] = temp;

        h->size -= 1;
        siftDown(h, 0);
    }
    //======下面是估算排序时间和验证排序的准确性,上面才是真正排序的代码=========

    c_end = clock();
    t_end = time(NULL);
    printf("\nThe sorting used %f ms by clock()\n",
           difftime(c_end, c_start) / CLOCKS_PER_SEC * 1000);
    printf("The sorting used %f s by time()\n", difftime(t_end, t_start));

    int prev = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < prev) {
            printf("\n========👎👎👎👎 not ascending order=============\n");
            return 0;
        }
        prev = array[i];
    }
    printf("\n========yes 👍👍👍👍👍 ascending order=============\n");

    free(array);

    return 0;
}

int main2() {
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
    int arr[] = {2, 1, 10, 21, 19, 6, 5, 12, 9};

    // int arr[] = {13, 76, 22, 56, 78, 26, 91, 59, 33, 62,
    //              63, 93, 68, 39, 65, 86, 41, 88, 20};
    // 93_88_91_86_63_78_65_59_76_56_62_22_68_26_39_13_41_33_20_
    // 93_88_91_86_78_63_68_65_56_76_62_62_26_22_13_39_59_33_41_62_20_
    int i;
    for (i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
        addElement(h, arr[i]);
    }
    dump(h);

    for (i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
        removelement(h);
        dump(h);
    }

    return 0;
}

int main1() {
    printf("%d\n", 0 << 1);
    printf("%d\n", 1 << 1);

    printf("%d\n", 2 << 1);
    printf("%d\n", 3 << 1);

    printf("%d\n", 4 << 1);
    printf("%d\n", 5 << 1);

    printf("%d\n", 6 << 1);
    printf("%d\n", 7 << 1);

    printf("%d\n", 8 << 1);
    printf("%d\n", 9 << 1);

    // printf("%d\n", 0 >> 1);
    // printf("%d\n", 1 >> 1);

    // printf("%d\n", 2 >> 1);
    // printf("%d\n", 3 >> 1);

    // printf("%d\n", 4 >> 1);
    // printf("%d\n", 5 >> 1);

    // printf("%d\n", 6 >> 1);
    // printf("%d\n", 7 >> 1);

    // printf("%d\n", 8 >> 1);
    // printf("%d\n", 9 >> 1);

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