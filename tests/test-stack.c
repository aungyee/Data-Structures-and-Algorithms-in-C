#include "data_structures.h"
#include <stdio.h>

int main(void) {
    printf("Test - Int Stack\n");
    stack *s = build_stack(3, sizeof(int));
    int a = 123;
    stack_push(s, &a);
    printf("The top element is %d\n", *(int *)stack_peek(s));
    stack_push(s, &a);
    stack_push(s, &a);
    stack_push(s, &a);

    stack_pop(s);
    stack_pop(s);
    stack_pop(s);
    stack_pop(s);

    printf("Test - Double Stack\n");
    stack *d = build_stack(2, sizeof(double));
    double c = 3.14;
    stack_push(d, &c);
    printf("The top element is %f\n", *(double *)stack_peek(d));
    stack_push(d, &c);
    stack_push(d, &c);
    
    stack_pop(d);
    stack_pop(d);
    stack_pop(d);

    return 0;
}
