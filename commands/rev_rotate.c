#include "../ft_push_swap.h"

void    ft_rev_rotate_a(t_stack *stack)
{
    if (stack && stack->size > 1)
    {
        ft_rev_rotate(stack);
    }
}

void    ft_rev_rotate_b(t_stack *stack)
{
    if (stack && stack->size > 1)
    {
        ft_rev_rotate(stack);
    }
}

void    ft_rev_rotate(t_stack *stack)
{
     if (stack && stack->size > 1)
    {
        stack->head = stack->tail;
        stack->tail = stack->tail->prev;
    }
}
