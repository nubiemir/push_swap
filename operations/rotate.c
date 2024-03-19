#include "../ft_push_swap.h"

void    ft_rotate_a(t_stack *stack)
{
    if (stack && stack->size > 1)
    {
        ft_rotate(stack);
        printf("ra\n");
    }
}

void    ft_rotate_b(t_stack *stack)
{
    if (stack && stack->size > 1)
    {
        ft_rotate(stack);
        printf("rb\n");
    }
}

void    ft_rotate(t_stack *stack)
{
    t_node *node;

    if (stack && stack->size > 1)
    {
        node = stack->head;
        stack->head = stack->head->next;
        node->prev = stack->tail;
        stack->tail = node;
        stack->tail->next = stack->head;
    }
}
