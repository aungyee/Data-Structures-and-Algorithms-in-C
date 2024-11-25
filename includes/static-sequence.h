#ifndef SEQUENCE_H

#define SEQUENCE_H

#include <stddef.h>

typedef struct {
    size_t length;
    size_t size;
    void *sequence;
} static_sequence;

static_sequence *build(size_t n, size_t size);

void destory(static_sequence *s);

size_t len_sequence(static_sequence *s);

void *get_at(static_sequence *s, size_t i);

void set_at(static_sequence *s, size_t i, void *x);


#endif // SEQUENCE_H

