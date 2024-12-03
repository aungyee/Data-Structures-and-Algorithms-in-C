#include <stdio.h>
#include "data_structures.h"

int main(void) {
    printf("Test - Int Queue\n");
    queue *q = build_queue(2, sizeof(int));
    int a = 123;
    int b = 234;
    queue_enqueue(q, &a);
    queue_enqueue(q, &b);
    queue_enqueue(q, &b);
    printf("The next item is: %d\n", *(int *)queue_peek(q));
    queue_dequeue(q);
    printf("The next item is: %d\n", *(int *)queue_peek(q));
    queue_dequeue(q);
    queue_dequeue(q);
    destory_queue(q);

    printf("Test - Double Queue\n");
    queue *r = build_queue(2, sizeof(double));
    double c = 3.14159;
    double d = 1.618;
    queue_enqueue(r, &c);
    queue_enqueue(r, &d);
    queue_enqueue(r, &d);
    printf("The next item is: %f\n", *(double *)queue_peek(r));
    queue_dequeue(r);
    printf("The next item is: %f\n", *(double *)queue_peek(r));
    queue_dequeue(r);
    queue_dequeue(r);
    destory_queue(r);
    return 0;
}
