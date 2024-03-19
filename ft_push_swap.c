#include "ft_push_swap.h"

t_stack *ft_push_swap(t_stack *stack_a, t_stack *stack_b)
{
    t_node *bottom_a;
    t_node *bottom_b;
    int max_a;
    int min_b;

    if (stack_a->size <= 3)
        return (ft_stack_of_three(stack_a));
    if (ft_check_sorted(stack_a))
        return (stack_a);

    bottom_a = stack_a->head;
    bottom_b = stack_b->head;

    while (bottom_a->data != stack_a->tail->data)
    {
        bottom_b = stack_b->head;
        if (bottom_a->data != stack_a->head->data)
        {
            max_a = stack_a->head->data;
        }
        else
        {
            max_a = stack_a->max + 1;
        }

        if (!bottom_b)
        {
            min_b = stack_a->min - 1;
        }
        else
        {
            min_b = stack_b->head->data;
        }

        if (!(stack_a->tail->data > min_b))
        {
            while (stack_b->head && stack_b->head->data > stack_a->tail->data)
            {
                ft_push_a(stack_a, stack_b);
            }
            ft_rev_rotate_a(stack_a);
            ft_push_b(stack_a, stack_b);
            continue;
        }
        if (stack_a->tail->data < max_a)
        {
            ft_rev_rotate_a(stack_a);
            continue;
        }
        else
        {
            while (stack_a->head->data != bottom_a->data && stack_a->tail->data > stack_a->head->data)
            {
                ft_push_b(stack_a, stack_b);
            }
            ft_rev_rotate_a(stack_a);
        }
    }

    if (stack_b->head && bottom_b->data > stack_b->head->data)
    {
        if (bottom_b->data < stack_a->head->data)
        {
            ft_rev_rotate_a(stack_a);
        }
        else
        {
            while (stack_a->head->data != bottom_a->data && stack_a->tail->data > stack_a->head->data)
            {
                ft_push_b(stack_a, stack_b);
            }
            ft_rev_rotate_a(stack_a);
        }
    }
    else
    {
        while (stack_b->head && stack_b->head->data > stack_a->tail->data)
        {
            ft_push_a(stack_a, stack_b);
        }
        ft_rev_rotate_a(stack_a);
        ft_push_b(stack_a, stack_b);
    }

    while (stack_b->size)
    {
        ft_push_a(stack_a, stack_b);
    }

    return (stack_a);
}
