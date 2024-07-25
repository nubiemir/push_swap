#include "../ft_push_swap.h"

void    ft_swap_a(t_stack *stack)
{
    if (stack && stack->size > 1)
    {
        ft_swap(stack);
    }
}

void    ft_swap_b(t_stack *stack)
{
    if (stack && stack->size > 1)
    {
        ft_swap(stack);
    }
}


void    ft_swap(t_stack *stack)
{
    t_node *top_node;
    t_node *nxt_node;

    if (stack && stack->size > 1)
    {
        top_node = stack->head;
        nxt_node = stack->head->next;
        if (stack->size == 2)
        {
            top_node->next = nxt_node;
            top_node->prev = nxt_node;
            stack->tail = top_node;
        }else
        {
            top_node->next = nxt_node->next;
            top_node->prev = nxt_node;
        }
        nxt_node->next = top_node;
        top_node->next->prev = top_node;
        stack->head = nxt_node;
        nxt_node->prev = stack->tail;
        stack->tail->next = stack->head;
    }
}

