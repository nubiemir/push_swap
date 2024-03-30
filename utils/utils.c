
#include "../ft_push_swap.h"

int     ft_find_max_position(t_stack *stack, int data)
{
    int position;
    t_node *ptr;

    ptr = stack->head;
    position = 0;
    while (position < stack->size && data != ptr->data)
    {
        ptr = ptr->next;
        position++;
    }
    return (position);
}

void     ft_find_position(t_stack *stack_a, t_stack *stack_b, int *coor)
{
    int left;
    t_node  *left_ptr;
    t_node  *right_ptr;

    left = 0;
    left_ptr = stack_a->head;
    right_ptr = stack_b->head;
    while (left < stack_a->size)
    {
       if (left_ptr->data < stack_b->min || left_ptr->data < stack_b->max)
       {
       }
       else
       {
       }
        left_ptr = left_ptr->next;
        left++;
    }
}
