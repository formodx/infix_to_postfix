#ifndef STACK_H
#define STACK_H


#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stack{
    int index;
    size_t element_size, capacity;
    void *data;
};


void stack_init(struct stack *, size_t, size_t);
void stack_free(struct stack *);
void stack_push(struct stack *, const void *);
void stack_pop(struct stack *);
void stack_top(struct stack *, void *);
bool stack_is_empty(const struct stack *);
bool stack_is_full(const struct stack *);


#endif