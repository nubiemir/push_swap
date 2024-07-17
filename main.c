#include "ft_push_swap.h"
#include <stdio.h>

int main(void)
{
    t_stack *stack_a = ft_create_stack();
    t_stack *stack_b = ft_create_stack();

    int x[] = {8, 4, 9, 3, 6, 1, 7, 2, 5, 10};

    for (int i = 0; i <= 9; i++)
        ft_push_stack(stack_a, x[i]);

    ft_push_b(stack_a, stack_b);
    ft_push_b(stack_a, stack_b);
    ft_push_b(stack_a, stack_b);

    while (stack_a->head &&  stack_a->head->data != stack_a->tail->data)
    {
        printf("%d\n", stack_a->head->data);
        stack_a->head = stack_a->head->next;
    }

    printf("%d\n", stack_b->head->data);
    printf("###################################\n");

    while (stack_b->head && stack_b->head->data != stack_b->tail->data)
    {
        printf("%d\n", stack_b->head->data);
        stack_b->head = stack_b->head->next;
    }
    printf("%d\n", stack_b->head->data);
}
