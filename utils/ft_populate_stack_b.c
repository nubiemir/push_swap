#include "../ft_push_swap.h"

int ft_min_checker(t_stack *stack)
{
    int idx;
    int min;

    idx = 0;
    min = stack->head->data;
    if (stack->head->next->data < min && stack->head->next->data < stack->head->prev->data)
        idx = 1;
    if (stack->head->prev->data < min && stack->head->prev->data < stack->head->next->data)
        idx = 2;
    return (idx);
}
int ft_max_checker(t_stack *stack)
{
    int idx;
    int max;

    idx = 0;
    max = stack->head->data;
    if (stack->head->next->data > max && stack->head->next->data > stack->head->prev->data)
        idx = 1;
    if (stack->head->prev->data > max && stack->head->prev->data > stack->head->next->data)
        idx = 2;
    return (idx);
}

void ft_populate_stack_b(t_stack *stack_a, t_stack *stack_b)
{
    int max_pos;
    int min_pos;

    while (stack_a->size > 5)
    {
        max_pos = ft_max_checker(stack_a);
        min_pos = ft_min_checker(stack_a);
        if (min_pos == 0 && max_pos == 2)
        {
            ft_push_b(stack_a, stack_b);
            ft_push_b(stack_a, stack_b);
            ft_rev_rotate_a(stack_a);
            ft_push_b(stack_a, stack_b);
        }
        else if (min_pos == 0 && max_pos == 1)
        {
            ft_push_b(stack_a, stack_b);
            ft_rev_rotate_a(stack_a);
            ft_push_b(stack_a, stack_b);
            ft_push_b(stack_a, stack_b);
        }

        else if (min_pos == 2 && max_pos == 0)
        {
            ft_rev_rotate(stack_a);
            ft_push_b(stack_a, stack_b);
            ft_swap_a(stack_a);
            ft_push_b(stack_a, stack_b);
            ft_push_b(stack_a, stack_b);
        }
        else if (min_pos == 1 && max_pos == 0)
        {
            ft_push_b(stack_a, stack_b);
            ft_push_b(stack_a, stack_b);
            ft_swap_b(stack_b);
            ft_rev_rotate_a(stack_a);
            ft_push_b(stack_a, stack_b);
            ft_swap_b(stack_b);
        }
        else if (min_pos == 1 && max_pos == 2)
        {
            ft_push_b(stack_a, stack_b);
            ft_push_b(stack_a, stack_b);
            ft_swap_b(stack_b);
            ft_rev_rotate_a(stack_a);
            ft_push_b(stack_a, stack_b);
        }
        else if (min_pos == 2 && max_pos == 1)
        {
            ft_rev_rotate_a(stack_a);
            ft_push_b(stack_a, stack_b);
            ft_push_b(stack_a, stack_b);
            ft_push_b(stack_a, stack_b);
        }
    }
    if (stack_a->size == 5)
    {
        if (stack_a->head->data < stack_a->head->next->data)
        {
            ft_push_b(stack_a, stack_b);
            ft_push_b(stack_a, stack_b);
        }
        else
        {
            ft_swap_a(stack_a);
            ft_push_b(stack_a, stack_b);
            ft_push_b(stack_a, stack_b);
        }
    }
    if (stack_a->size == 4)
    {
        ft_push_b(stack_a, stack_b);
    }
    ft_stack_of_three(stack_a);
}
