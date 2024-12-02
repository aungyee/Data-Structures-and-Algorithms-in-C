#ifndef _STACK_H

#define _STACK_H

#include "stack.h"
#include <stddef.h>

typedef struct {
    size_t length;
    size_t top;
    int *sequence;
} stack;

stack * build(size_t length);

void push(stack *s, int x);

void pop(stack *s);

void destory(stack *s);

#endif // _STACK_H

