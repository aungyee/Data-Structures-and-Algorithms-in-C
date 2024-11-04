/* 

A static sequence is a sequence of fix length.
It implements the following interface -
    1. build(n) - build a sequence of size n
    2. len_sequence(s) - get the length of sequence s
    3. get_at(s, i) - get the element at index i
    4. set_at(s, i, x) - set the element at index i to x
    5. print_sequence(s) - print out all the elements
    6. destory(s) - destroy the sequece and free memory

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct  {
    size_t length;
    int *sequence;
} static_sequence;

static_sequence * build(size_t n) {
    static_sequence * a = malloc(sizeof(static_sequence));
    a->length = n;
    a->sequence = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        a->sequence[i] = 0;
    }
    return a;
}

void destory(static_sequence * s) {
    free(s->sequence);
    free(s);
}

size_t len_sequence(static_sequence * s) {
    return s->length;
}

void print_sequence(static_sequence * s) {
    for(int i = 0; i < len_sequence(s); i++) {
        if (i == 0) {
            printf("%d", s->sequence[i]);
        } else {
            printf(", %d", s->sequence[i]);
        }
    }
    printf("\n");
}

int get_at(static_sequence * s, size_t i) {
    if (i >= len_sequence(s)) {
        printf("get_at: Index %zu is out of bound for sequence s. \n", i);
        return errno;
    } else {
        return s->sequence[i];
    }
}

void set_at(static_sequence * s, size_t i, int x) {
    if (i >= len_sequence(s)) {
        printf("set_at: Index %zu is out of bound for sequence s. \n", i);
    } else {
        s->sequence[i] = x;
    }
}

int main() {
    static_sequence * s = build(10);
    print_sequence(s);
    printf("Length of s = %zu \n", len_sequence(s));
    set_at(s, 9, 199);
    printf("s[0] = %d \n", get_at(s, 9));
    print_sequence(s);
    destory(s);
    return 0;
}