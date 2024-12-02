#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures.h"

static_sequence *build_static_sequence(size_t n, size_t size) {
    static_sequence *a = malloc(sizeof(static_sequence));
    a->length = n;
    a->size = size;
    a->sequence = malloc(n * size);
    return a;
}

void destory_static_sequence(static_sequence *s) {
    free(s->sequence);
    free(s);
}

size_t static_sequence_len(static_sequence *s) {
    return s->length;
}

void *static_sequence_get_at(static_sequence *s, size_t i) {
    if (i >= static_sequence_len(s)) {
        printf("get_at: Index %zu is out of bound for sequence s.\n", i);
        exit(1);
    } else {
        return (void *)((char *)s->sequence + (i * s->size));
    }
}

void static_sequence_set_at(static_sequence *s, size_t i, void *x) {
    if (i >= static_sequence_len(s)) {
        printf("set_at: Index %zu is out of bound for sequence s.\n", i);
        exit(1);
    } else {
        memcpy((char *)s->sequence + (i * s->size), x, s->size);
    }
}

