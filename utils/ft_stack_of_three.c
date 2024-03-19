#include "../ft_push_swap.h"

t_stack *ft_stack_of_two(t_stack *stack)
{
    if (!stack)
        return (NULL);
    if (stack->min == stack->head->data)
        return (stack);
    ft_rotate_a(stack);
    return (stack);
}

t_stack *ft_stack_of_three(t_stack *stack)
{
    if (!stack || stack->size == 0)
        return (NULL);
    if (stack->size == 1)
        return (stack);
    if (stack->size == 2)
        return (ft_stack_of_two(stack));
    if (stack->head->data == stack->min && stack->tail->data == stack->max)
        return (stack);
    if (stack->head->data == stack->min)
        return (ft_rev_rotate_a(stack), ft_swap_a(stack), stack);
    if (stack->head->data == stack->max && stack->tail->data == stack->min)
        return (ft_swap_a(stack), ft_rev_rotate_a(stack), stack);
    if (stack->head->data == stack->max)
        return (ft_rotate_a(stack), stack);
    if (stack->tail->data == stack->max)
        return (ft_swap_a(stack), stack);
    if (stack->tail->data == stack->min)
        return (ft_rev_rotate_a(stack), stack);
    return (stack);
}
