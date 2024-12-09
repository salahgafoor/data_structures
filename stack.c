#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int * arr;
};

struct Stack * create_stack(int size)
{
    struct Stack * stack_obj = (struct Stack *)malloc(sizeof(struct Stack));
    stack_obj->top = -1;
    stack_obj->capacity = size;
    stack_obj->arr = (int*)malloc(size * sizeof(int));
    return stack_obj;
}

int is_empty(struct Stack *stack_obj)
{
    return stack_obj->top == -1;
}

int is_full(struct Stack *stack_obj)
{
    return stack_obj->top == (stack_obj->capacity - 1);
}

int push(struct Stack * stack_obj, int item)
{
    if(is_full(stack_obj))
    {
        return INT_MIN;
    }
    stack_obj->arr[++stack_obj->top] = item;
    printf("%d is added; top  = %d\n",item, stack_obj->top);
}

int pop(struct Stack *stack_obj)
{
    if(is_empty(stack_obj))
    {
        return INT_MIN;
    }
    int item = stack_obj->arr[stack_obj->top--];
    printf("%d is removed; top = %d\n", item, stack_obj->top);    
}

int main()
{
    struct Stack * stack_obj = create_stack(5);
    push(stack_obj, 10);
    push(stack_obj, 20);
    push(stack_obj, 30);
    push(stack_obj, 40);
    push(stack_obj, 50);
    push(stack_obj, 60);
    pop(stack_obj);
    pop(stack_obj);
    pop(stack_obj);
    return 0;
}
