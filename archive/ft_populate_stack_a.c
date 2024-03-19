#include "../ft_push_swap.h"

void ft_rotate_to_position(t_stack *stack_a, t_stack *stack_b, int(ft_find_position)(t_stack *, int))
{
    int idx;
    int counter;

    counter = 0;
    idx = ft_find_position(stack_a, stack_b->head->data);
    if (idx > stack_a->size / 2)
    {
        while (counter < stack_a->size - idx)
        {
            ft_rev_rotate_a(stack_a);
            counter++;
        }
    }
    else
    {
        while (counter < idx)
        {
            ft_rotate_a(stack_a);
            counter++;
        }
    }
    ft_push_a(stack_a, stack_b);
}

void ft_smallest_rotation(t_stack *stack_a, t_stack *stack_b)
{
    int idx;
    int counter;

    counter = 0;
    if (stack_a->min > stack_b->head->data)
    {
        idx = ft_position(stack_a, stack_a->min);
        if (idx == 0)
            return (ft_push_a(stack_a, stack_b));
        if (idx > stack_a->size / 2)
        {
            while (counter < stack_a->size - idx)
            {
                ft_rev_rotate_a(stack_a);
                counter++;
            }
        }
        else
        {
            while (counter < idx)
            {
                ft_rotate_a(stack_a);
                counter++;
            }
        }
        return (ft_push_a(stack_a, stack_b));
    }

    if (stack_a->head->data < stack_a->tail->data)
    {
        while (stack_a->tail->data < stack_b->head->data)
            ft_rotate_a(stack_a);
        return (ft_push_a(stack_a, stack_b));
    }
    if (stack_a->head->data > stack_a->tail->data)
    {
        while (stack_a->tail->data > stack_b->head->data)
            ft_rev_rotate_a(stack_a);
        ft_push_a(stack_a, stack_b);
    }
}
void ft_biggest_rotation(t_stack *stack_a, t_stack *stack_b)
{
    int idx;
    int counter;

    counter = 0;
    if (stack_a->max < stack_b->head->data)
    {
        idx = ft_position(stack_a, stack_a->max);
        if (idx == stack_a->size - 1)
            return (ft_push_a(stack_a, stack_b), ft_rotate_a(stack_a));
        if (idx > stack_a->size / 2)
        {
            while (counter < stack_a->size - idx - 1)
            {
                ft_rev_rotate_a(stack_a);
                counter++;
            }
        }
        else
        {
            while (counter < idx + 1)
            {
                ft_rotate_a(stack_a);
                counter++;
            }
        }
        return (ft_push_a(stack_a, stack_b));
    }

    if (stack_a->tail->data > stack_a->head->data)
    {
        while (stack_a->head->data > stack_b->head->data)
            ft_rev_rotate_a(stack_a);
        return (ft_push_a(stack_a, stack_b));
    }
    if (stack_a->head->data > stack_a->tail->data)
    {
        while (stack_a->head->data < stack_b->head->data)
            ft_rotate_a(stack_a);
        ft_push_a(stack_a, stack_b);
    }
}

void ft_populate_stack_a(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b->head->data < stack_a->head->data && stack_b->head->data > stack_a->tail->data)
    {
        // ft_rotate_to_position(stack_a, stack_b, ft_find_less_position);
        // return (ft_rotate_a(stack_a));
        // return (ft_biggest_rotation(stack_a, stack_b));
        return (ft_push_a(stack_a, stack_b));
    }
    if (stack_b->head->data > stack_a->head->data && stack_b->head->data < stack_a->tail->data)
        return (ft_rotate_to_position(stack_a, stack_b, ft_find_great_position));
    if (stack_b->head->data < stack_a->head->data && stack_b->head->data < stack_a->tail->data)
        return (ft_smallest_rotation(stack_a, stack_b));
    if (stack_b->head->data > stack_a->head->data && stack_b->head->data > stack_a->tail->data)
        return (ft_biggest_rotation(stack_a, stack_b));
}

// 1707
// 1715
// 227
// 410