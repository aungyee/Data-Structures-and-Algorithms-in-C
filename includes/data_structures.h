#ifndef DATA_STRUCTURE_H

#define DATA_STRUCTURE_H

#include <stddef.h>


/* 

Static Sequence

A static sequence is a sequence of fix length.

Interface:
    1. build(n, s) - build a sequence of n item, each is s byte
    2. len_sequence(s) - get the length of sequence s
    3. get_at(s, i) - get the element at index i
    4. set_at(s, i, x) - set the element at index i to x
    5. destory(s) - destroy the sequece and free memory

*/

typedef struct {
    size_t length;
    size_t size;
    void *sequence;
} static_sequence;

static_sequence *build_static_sequence(size_t n, size_t size);

void destory_static_sequence(static_sequence *s);

size_t static_sequence_len(static_sequence *s);

void *static_sequence_get_at(static_sequence *s, size_t i);

void static_sequence_set_at(static_sequence *s, size_t i, void *x);


/*

Stack

A stack is a dynamic set with a pre-specified `DELETE` operation implementing last in first out (LIFO) policy.

Interface:
1. build(n, s) - initiate a stack of size n which each element having a size of s byte
2. push(s, x) - push the element x onto the stack s
3. pop(s) - remove the last element from the stack s
4. peek(s) - get the last element from the stack s
5. destory(s) - destory stack s

*/


typedef struct {
    size_t length;
    size_t size;
    size_t top;
    void *sequence;
} stack;

stack * build_stack(size_t length, size_t size);

void destory_stack(stack *s);

void stack_push(stack *s, void *x);

void stack_pop(stack *s);

void *stack_peek(stack *s);


/*

Queue

A queue implements first in first out (FIFO) policy.

Interface:

1. build(n, s) - initiate a queue of n item with each element having a size of s byte
2. enqueue(q, x) - push x onto queue
3. dequeue(q) - remove the next element from queue
4. peek(q) - get the next element from queue
5. destory(q) - destory queue and free memory
*/

typedef struct {
    size_t length;
    size_t size;
    size_t top;
    size_t bottom;
    size_t item;
    void * sequence;
} queue;

queue *build_queue(size_t length, size_t size);

void queue_enqueue(queue *q, void *x);

void queue_dequeue(queue *q);

void *queue_peek(queue *q);

void destory_queue(queue *q);

#endif // DATA_STRUCTURE_H

