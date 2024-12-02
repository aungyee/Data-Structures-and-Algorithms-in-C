#include <stdio.h>
#include "data_structures.h"

int main() {
    printf("Testing Integer\n");
    static_sequence *s = build_static_sequence(10, sizeof(int));
    printf("Length of s = %zu\n", static_sequence_len(s));
    int x = 199;
    static_sequence_set_at(s, 9, &x);
    printf("s[9] = %d\n", *(int *)static_sequence_get_at(s, 9));
    destory_static_sequence(s);

    printf("Testing Char\n");
    static_sequence *c = build_static_sequence(10, sizeof(char));
    printf("Length of c = %zu\n", static_sequence_len(c));
    char a = 'a';
    static_sequence_set_at(c, 9, &a);
    printf("c[9] = %c\n", *(char *)static_sequence_get_at(c, 9));
    destory_static_sequence(c);

    printf("Testing Double\n");
    static_sequence *d = build_static_sequence(10, sizeof(double));
    printf("Length of d = %zu\n", static_sequence_len(d));
    double du = 3.14159;
    static_sequence_set_at(d, 9, &du);
    printf("d[9] = %f\n", *(double *)static_sequence_get_at(d, 9));
    destory_static_sequence(d);

    return 0;
}

