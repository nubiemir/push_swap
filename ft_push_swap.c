#include "ft_push_swap.h"
#include <stdio.h>

t_stack *ft_push_swap(int *arr, t_stack *stack_a, t_stack *stack_b)
{
    int max_digit;
    int i;
    int j;
    int idx;

    i = 0;
    // if (ft_check_sorted(stack_a))
    //     return (stack_a);
    if (stack_a->size <= 3)
        return (ft_stack_of_three(stack_a));
    max_digit = ft_max_digit(stack_a);
    while (i < max_digit)
    {
        idx = 31 - i;
        j = 0;
        int size_a = stack_a->size;
        while (j <= size_a - 1)
        {
            if (stack_a->head->binary[idx] == 0)
            {
                ft_push_b(stack_a, stack_b);
                printf("pb\n");
            }
            else
            {
                ft_rotate_a(stack_a);
                printf("ra\n");
            }
            j++;
        }
        j = 0;
        int size_b = stack_b->size;
        while (j <= size_b - 1)
        {
            if (stack_b->head->binary[idx - 1] == 0 && i + 1 < max_digit)
            {
                ft_rotate_b(stack_b);
                printf("rb\n");
            }
            else
            {
                ft_push_a(stack_a, stack_b);
                printf("pa\n");
            }
            j++;
        }
        i++;
    }
    return (stack_a);
}
