#include "../ft_push_swap.h"

void ft_find_position(t_stack *stack, int *arr, int *ptr, int left, int right)
{
    t_node *tmp_node;
    int counter;

    counter = 0;
    tmp_node = stack->head;
    while (counter < stack->size)
    {
        if (arr[left] == tmp_node->data)
            ptr[0] = counter;
        if (arr[right] == tmp_node->data)
            ptr[1] = counter;
        ++counter;
        tmp_node = tmp_node->next;
    }
}

int ft_operation_counter(int pos, int size)
{
    if (pos < size - pos)
        return pos;
    else
        return size - pos;
}

void ft_oryx_rotation(int pos, t_stack *stack_a, t_stack *stack_b)
{
    int operations;
    int mid;

    mid = stack_a->size / 2;
    operations = ft_operation_counter(pos, stack_a->size);
    if (pos <= mid)
    {
        while (operations > 0)
        {
            ft_rotate_a(stack_a);
            --operations;
        }
        ft_push_b(stack_a, stack_b);
        return;
    }
    while (operations > 0)
    {
        ft_rev_rotate_a(stack_a);
        --operations;
    }
    ft_push_b(stack_a, stack_b);
}

void ft_oryx(int *ptr, t_stack *stack_a, t_stack *stack_b)
{
    int left;
    int right;
    int mid;
    int right_operations;
    int left_operations;

    left = ptr[0];
    right = ptr[1];
    mid = stack_a->size / 2;
    right_operations = ft_operation_counter(right, stack_a->size);
    left_operations = ft_operation_counter(left, stack_a->size);
    if (right_operations < left_operations)
    {
        if (right <= mid)
        {
            while (right_operations > 0)
            {
                ft_rotate_a(stack_a);
                --left;
                --right_operations;
            }
        }
        else
        {
            while (right_operations > 0)
            {
                ft_rev_rotate_a(stack_a);
                ++left;
                --right_operations;
            }
        }
        ft_push_b(stack_a, stack_b);
        --left;
        ft_oryx_rotation(left, stack_a, stack_b);
    }
    else
    {
        if (left <= mid)
        {
            while (left_operations > 0)
            {
                ft_rotate_a(stack_a);
                --right;
                --left_operations;
            }
        }
        else
        {
            while (left_operations > 0)
            {
                ft_rev_rotate_a(stack_a);
                ++right;
                --left_operations;
            }
        }
        ft_push_b(stack_a, stack_b);
        --right;
        ft_oryx_rotation(right, stack_a, stack_b);
    }
}

void ft_populate_stack_b(int *arr, t_stack *stack_a, t_stack *stack_b)
{
    int ptr[2];
    int left;
    int right;

    left = 0;
    right = 1;
    ft_find_position(stack_a, arr, ptr, left, right);
    while (stack_a->size > 3)
    {
        ft_oryx(ptr, stack_a, stack_b);
        if (stack_b->head->data < stack_b->head->next->data)
            ft_swap_b(stack_b);
        left += 2;
        right += 2;
        ft_find_position(stack_a, arr, ptr, left, right);
    }
    ft_stack_of_three(stack_a);
}
