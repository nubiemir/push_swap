#include "../ft_push_swap.h"
#include <stdio.h>

void    ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *node;

    node = ft_pop_stack(stack_a);
    if (node)
    {
        ft_push_stack(stack_b, node->data);
        safe_free((void **)&node);
        printf("pb\n");
    }
}

void    ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
    t_node *node;

    node = ft_pop_stack(stack_b);
    if (node)
    {
        ft_push_stack(stack_a, node->data);
        safe_free((void **)&node);
        printf("pa\n");
    }
}
