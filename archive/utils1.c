#include "../ft_push_swap.h"

int ft_find_great_position(t_stack *stack, int data)
{
    t_node *ptr;
    int idx;

    ptr = stack->head;
    idx = 0;
    while (ptr->data != stack->tail->data && ptr->data < data)
    {
        ptr = ptr->next;
        idx++;
    }
    return (idx);
}

int ft_find_less_position(t_stack *stack, int data)
{
    t_node *ptr;
    int idx;

    ptr = stack->head;
    idx = 0;
    while (ptr->data != stack->tail->data && ptr->data > data)
    {
        ptr = ptr->next;
        idx++;
    }
    return (idx);
}
