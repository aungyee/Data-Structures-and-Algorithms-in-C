/* 

A static sequence is a sequence of fix length.
It implements the following interface -
    1. build(n, s) - build a sequence of n item, each is s byte
    2. len_sequence(s) - get the length of sequence s
    3. get_at(s, i) - get the element at index i
    4. set_at(s, i, x) - set the element at index i to x
    5. destory(s) - destroy the sequece and free memory

*/

#include "static-sequence.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static_sequence *build(size_t n, size_t size) {
    static_sequence *a = malloc(sizeof(static_sequence));
    a->length = n;
    a->size = size;
    a->sequence = malloc(n * size);
    return a;
}

void destory(static_sequence *s) {
    free(s->sequence);
    free(s);
}

size_t len_sequence(static_sequence *s) {
    return s->length;
}

void *get_at(static_sequence *s, size_t i) {
    if (i >= len_sequence(s)) {
        printf("get_at: Index %zu is out of bound for sequence s.\n", i);
        exit(1);
    } else {
        return (void *)((char *)s->sequence + (i * s->size));
    }
}

void set_at(static_sequence *s, size_t i, void *x) {
    if (i >= len_sequence(s)) {
        printf("set_at: Index %zu is out of bound for sequence s.\n", i);
        exit(1);
    } else {
        memcpy((char *)s->sequence + (i * s->size), x, s->size);
    }
}

