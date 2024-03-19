#include "ft_push_swap.h"

void ft_final_rotation(t_stack *stack)
{
    int counter;
    int idx;

    counter = 0;
    idx = ft_position(stack, stack->min);
    if (idx == 0)
        return;
    if (idx == stack->size - 1)
        return (ft_rev_rotate_a(stack));
    if (idx > stack->size / 2)
    {
        while (counter < stack->size - idx)
        {
            ft_rev_rotate_a(stack);
            counter++;
        }
    }
    else
    {
        while (counter < idx)
        {
            ft_rotate_a(stack);
            counter++;
        }
    }
}

t_stack *ft_push_swap(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 3)
        return (ft_stack_of_three(stack_a));
    if (ft_check_sorted(stack_a))
        return (stack_a);
    ft_populate_stack_b(stack_a, stack_b);
    // while (stack_b->head)
    //     ft_populate_stack_a(stack_a, stack_b);
    // ft_final_rotation(stack_a);
    return (stack_a);
}
