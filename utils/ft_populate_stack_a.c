#include "../ft_push_swap.h"

int ft_calculate_operations(int size_a, int size_b, t_chosen *chosen_node)
{
    return (0);
}

t_chosen *ft_find_chosen(t_stack *stack_a, t_stack *stack_b)
{
    t_node *ptr_a;
    t_node *ptr_b;
    t_chosen *chosen_node;
    int counter;

    ptr_a = stack_a->head;
    ptr_b = stack_b->head;
    chosen_node = ft_create_chosen();
    counter = 0;
    while (ptr_b->data != stack_b->tail->data)
    {
        if (ptr_b->data < stack_a->min)
        {
            chosen_node->position_b = counter;
            chosen_node->position_a = ft_position(stack_a, stack_a->min);
        }
        else if (ptr_b->data > stack_a->max)
        {
            chosen_node->position_b = counter;
            chosen_node->position_a = ft_position(stack_a, stack_a->max);
        }
        else
        {
            while (ptr_a->data != stack_a->tail->data)
            {
            }
        }
        counter++;
    }
}

void ft_populate_stack_a(t_stack *stack_a, t_stack *stack_b)
{
    int idx;

    if (stack_a->min > stack_b->head->data)

        idx = ft_position(stack_a, stack_a->min);
}
