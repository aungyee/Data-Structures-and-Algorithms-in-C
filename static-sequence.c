/* 

A static sequence is a sequence of fix length.
It implements the following interface -
    1. build(n) - build a sequence of size n
    2. len_sequence(s) - get the length of sequence s
    3. get_at(s, i) - get the element at index i
    4. set_at(s, i, x) - set the element at index i to x
    5. destory(s) - destroy the sequece and free memory

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
    size_t length;
    size_t size;
    void *sequence;
} static_sequence;

static_sequence *build(size_t n, size_t size) {
    static_sequence *a = malloc(sizeof(static_sequence));
    a->length = n;
    a->size = size;
    a->sequence = malloc(n * size); 
    return a;
}

void destory(static_sequence * s) {
    free(s->sequence);
    free(s);
}

size_t len_sequence(static_sequence * s) {
    return s->length;
}

void *get_at(static_sequence * s, size_t i) {
    if (i >= len_sequence(s)) {
        printf("get_at: Index %zu is out of bound for sequence s. \n", i);
        exit(1);
    } else {
        return (void *)((char *)s->sequence + (i * s->size));
    }
}

void set_at(static_sequence * s, size_t i, void *x) {
    if (i >= len_sequence(s)) {
        printf("set_at: Index %zu is out of bound for sequence s. \n", i);
        exit(1);
    } else {
        memcpy((char *)s->sequence + (i * s->size), x, s->size); 
    }
}

int main() {
    printf("Testing Integer\n");
    static_sequence *s = build(10, sizeof(int));
    printf("Length of s = %zu \n", len_sequence(s));
    int x = 199;
    set_at(s, 9, &x);
    printf("s[9] = %d \n", *(int *)get_at(s, 9));
    destory(s);
    printf("Testing Char\n");
    static_sequence *c = build(10, sizeof(char));
    printf("Length of c = %zu \n", len_sequence(c));
    char a = 'a';
    set_at(c, 9, &a);
    printf("c[9] = %c \n", *(char *)get_at(c, 9));
    destory(c);
    printf("Testing Double\n");
    static_sequence *d = build(10, sizeof(double));
    printf("Length of d = %zu \n", len_sequence(d));
    double du = 3.14159;
    set_at(d, 9, &du);
    printf("d[9] = %f \n", *(double *)get_at(d, 9));
    destory(d);
    return 0;
}
