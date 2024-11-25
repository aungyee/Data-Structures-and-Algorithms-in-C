#include <stdio.h>
#include "static-sequence.h"

int main() {
    printf("Testing Integer\n");
    static_sequence *s = build(10, sizeof(int));
    printf("Length of s = %zu\n", len_sequence(s));
    int x = 199;
    set_at(s, 9, &x);
    printf("s[9] = %d\n", *(int *)get_at(s, 9));
    destory(s);

    printf("Testing Char\n");
    static_sequence *c = build(10, sizeof(char));
    printf("Length of c = %zu\n", len_sequence(c));
    char a = 'a';
    set_at(c, 9, &a);
    printf("c[9] = %c\n", *(char *)get_at(c, 9));
    destory(c);

    printf("Testing Double\n");
    static_sequence *d = build(10, sizeof(double));
    printf("Length of d = %zu\n", len_sequence(d));
    double du = 3.14159;
    set_at(d, 9, &du);
    printf("d[9] = %f\n", *(double *)get_at(d, 9));
    destory(d);

    return 0;
}

