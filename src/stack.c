#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures.h"

stack *build_stack(size_t length, size_t size) {
    stack *s = malloc(sizeof(stack));
    s->length = length;
    s->size = size;
    s->top = 0;
    s->sequence = malloc(size * length);
    return s;
}

void stack_push(stack *s, void *x) {
    if (s->top >= s->length * s->size) {
        printf("The stack is full!\n");
        return;
    }

    memcpy((char *)s->sequence + s->top, x, s->size);
    s->top += s->size;
}

void stack_pop(stack *s) {
    if (s->top == 0) {
        printf("The stack is empty!\n");
        return;
    }

    s->top -= s->size;
}

void *stack_peek(stack *s) {
    if (s->top == 0) {
        printf("The stack is empty!\n");
        return NULL;
    }

    return s->sequence + s->top - s->size;
}

void destory_stack(stack *s) {
    free(s->sequence);
    free(s);
}

