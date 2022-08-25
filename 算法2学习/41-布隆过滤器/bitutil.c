#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "bitutil.h"

#define BITS_IN_BYTE 8
#define BITS_IN_TYPE(type) (BITS_IN_BYTE * (sizeof(type)))

/**
 * @brief Allocates dynamic memory for a new bit_vect structure on the heap
 *
 * @param num_bits The number of bits contained in the bit_vect
 * @return bit_vect*
 */
bit_vect *bit_vect_new(size_t num_bits) {
    bit_vect *vect = malloc(sizeof(*vect));
    if (NULL == vect) {
        fprintf(stderr, "Out of memory.\n");
        exit(EXIT_FAILURE);
    }

    /**
    BITS_IN_TYPE(uint32_t) 
    (BITS_IN_BYTE * (sizeof(type)))
    uint32_t 是4个字节 1个字节是8位
    这里就是根据size来计算要多少个uint32_t
     */
    size_t mem_size = num_bits / BITS_IN_TYPE(uint32_t);
    if (!(num_bits % BITS_IN_TYPE(uint32_t))) {
        mem_size++;
    }
    vect->mem = calloc(mem_size, sizeof(*(vect->mem)));
    if (NULL == vect->mem) {
        fprintf(stderr, "Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    vect->size = num_bits;
    return vect;
}

/**
 * @brief Frees the memory associated with a bit_vect structure allocated on the
 * heap
 *
 * @param vect The memory that will be de-allocated
 */
void bit_vect_free(bit_vect *vect) {
    free(vect->mem);
    free(vect);
}

/**
 * @brief Gets the value associated with the bith at index position
 *
 * @param vect The bit_vect were we keep the bits
 * @param bit_idx The bit we would like to retrieve
 * @return true If the bit is 1
 * @return false If the bit is 0
 */
bool bit_vect_get(bit_vect *vect, size_t bit_idx) {
    if (bit_idx >= vect->size) {
        fprintf(stderr, "Out of bounds bit_idx=%zu, vect->size=%zu\n", bit_idx,
                vect->size);
        exit(EXIT_FAILURE);
    }

    /*
    chunk_offset 找出是哪一个uint32_t 1个uint32_t是32位 所以直接用bit_idx/32就行
    比如 bit_idx = 100
    100/32 = 3.125 = 3(size_t)

    bit_offset 找出是uint32_t的哪一位
    100%32 = 4(第4位)
    下标为3的uint32_t, 是97 98 99 100
    也可以转换为与运算 (参考: https://blog.csdn.net/weixin_48052161/article/details/121444170)
    十进制的100转成二进制是 0110 0100 (bit_idx)
    十进制的31转成二进制是  0001 1111 (BITS_IN_TYPE(uint32_t) - 1)
    做与运算后是 0000 0100   

      97   65   33    0               
    0000 0000 0000 0000 

    uint32_t byte = vect->mem[chunk_offset]; 是把第3个uint32_t取出 
    然后取出 byte 的第 bit_offset 位 看是0还是1
    byte & (1 << bit_offset)
    (byte >> bit_offset) & 1
    */

    size_t chunk_offset = bit_idx / BITS_IN_TYPE(uint32_t);
    size_t bit_offset = bit_idx & (BITS_IN_TYPE(uint32_t) - 1);
    uint32_t byte = vect->mem[chunk_offset];
    return byte & (1 << bit_offset);
}

/**
 * @brief Sets the bit_idx to 1 or 0.
 *
 * @param vect The bit_vect were we keep the bits
 * @param bit_idx The index of the bit we want to modify
 * @param val 0 (false) or 1 (true)
 */
void bit_vect_set(bit_vect *vect, size_t bit_idx, bool val) {
    if (bit_idx >= vect->size) {
        fprintf(stderr, "Out of bounds bit_idx=%zu, vect->size=%zu\n", bit_idx,
                vect->size);
        exit(EXIT_FAILURE);
    }
    size_t chunk_offset = bit_idx / BITS_IN_TYPE(uint32_t);
    size_t bit_offset = bit_idx & (BITS_IN_TYPE(uint32_t) - 1);
    uint32_t *byte = &(vect->mem[chunk_offset]);

    /*
    把二进制某一位设置为1
    十进制的100转成二进制是 0110 0100 
    如果相比第1位设置为1, 也就是想要得到 0110 0110
    用或运算 
        和1做或运算结果都是1 
        和0做或运算结果都是本身 0是0 1是1

      0110 0100
    | 0000 0010
    -----------
      0110 0110
    */

    /*
    把二进制某一位设置为0
    十进制的100转成二进制是 0110 0100 
    如果相比第2位设置为0, 也就是想要得到 0110 0000
    用与运算 
        和1做与运算结果都是本身 0是0 1是1
        和0做与运算都是0
    
      0110 0100
    | 1111 1011
    -----------
      0110 0000

    1111 1011 是怎么得来的?
    先把1左移2位 -> 再取反
    0000 0001 -> 0000 0100 -> 1111 1011
    */
    if (val) {
        // Sets the the `bit_idx` to 1 (true)
        *byte |= ((uint32_t)1) << bit_offset;
    } else {
        // Sets the bit `bit_idx` to 0 (false)
        *byte &= ~(1 << bit_offset);
    }
}

/**
 * @brief Sets the bit_idx inside the vect to 1 (true)
 */
void bit_vect_set1(bit_vect *vect, size_t bit_idx) {
    bit_vect_set(vect, bit_idx, true);
}

/**
 * @brief Sets the bit_idx inside the vect to 0 (true)
 */
void bit_vect_set0(bit_vect *vect, size_t bit_idx) {
    bit_vect_set(vect, bit_idx, false);
}
