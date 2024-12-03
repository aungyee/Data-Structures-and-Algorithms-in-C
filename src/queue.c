#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures.h"

queue *build_queue(size_t length, size_t size) {
    queue *q = malloc(sizeof(queue));
    q->length = length;
    q->size = size;
    q->top = 0;
    q->bottom = 0;
    q->item = 0;
    q->sequence = malloc(length * size);
    return q;
}

void destory_queue(queue *q) {
    free(q->sequence);
    free(q);
}

void queue_enqueue(queue *q, void *x) {
    if (q->item == q->length) {
        printf("Enqueue: Queue is Full\n");
        return;
    }

    memcpy((char *)q->sequence + (q->top), x, q->size);
    q->top = (q->top + q->size) % (q->length * q->size);
    q->item += 1;
}

void queue_dequeue(queue *q) {
    if (q->item == 0) {
        printf("Dequeue: Queue is Empty\n");    
        return;
    }
    q->item -= 1;
    q->bottom = (q->bottom + q->size) % (q->length * q->size);
}

void *queue_peek(queue *q) {
    if (q->item == 0) {
        printf("Peek: Queue is Empty\n");
        return NULL;
    }
    return q->sequence + q->bottom;
}

