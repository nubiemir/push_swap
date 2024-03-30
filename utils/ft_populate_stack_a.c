#include "../ft_push_swap.h"

void    ft_populate_stack_a(t_stack *stack_a, t_stack *stack_b)
{
    while(stack_b->size > 0)
        ft_push_a(stack_a, stack_b);
}
