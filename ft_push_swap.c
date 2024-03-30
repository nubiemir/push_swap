#include "ft_push_swap.h"

t_stack *ft_push_swap(int *arr, t_stack *stack_a, t_stack *stack_b)
{

    if (ft_check_sorted(stack_a))
        return (stack_a);
    if (stack_a->size <= 3)
        return (ft_stack_of_three(stack_a));
    ft_populate_stack_b(arr, stack_a, stack_b);
    ft_populate_stack_a(stack_a, stack_b);
    return (stack_a);
}
