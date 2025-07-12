#include "stack.h"


void stack_init(struct stack *stack, size_t size, size_t count){
    stack->index = -1;
    stack->element_size = size;
    stack->capacity = count;
    stack->data = malloc(stack->element_size * stack->capacity);
}


void stack_free(struct stack *stack){
    stack->index = -1;
    stack->element_size = 0;
    stack->capacity = 0;
    free(stack->data);
}


void stack_push(struct stack *stack, const void *element){
    stack->index++;

    if(stack_is_full(stack)){
        fprintf(stderr, "stack is full");
        exit(EXIT_FAILURE);
    }

    memcpy((char *) stack->data + (stack->element_size*stack->index), element, stack->element_size);
}


void stack_pop(struct stack *stack){
    if(stack_is_empty(stack)){
        fprintf(stderr, "stack is empty");
        exit(EXIT_FAILURE);
    }

    stack->index--;
}


void stack_top(struct stack *stack, void *element){
    if(stack_is_empty(stack)){
        fprintf(stderr, "stack is empty");
        exit(EXIT_FAILURE);
    }

    memcpy(element, (char *) stack->data + (stack->element_size*stack->index), stack->element_size);
}


bool stack_is_empty(const struct stack *stack){
    return stack->index == -1;
}


bool stack_is_full(const struct stack *stack){
    return stack->index+1 == stack->capacity;
}