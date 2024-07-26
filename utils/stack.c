#include "../ft_push_swap.h"
#include <stdio.h>

t_node *ft_create_node(int data, int binary[32])
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    for(int i =0; i <= 31; i++)
        new_node->binary[i] = binary[i];
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}

void ft_push_stack(t_stack *stack, t_node *new_node)
{
    t_node *tmp_node;

    if (!stack->size)
    {
        stack->head = new_node;
        stack->tail = new_node;
        stack->head->next = stack->tail;
        stack->head->prev = stack->tail;
    }
    else
    {
        tmp_node = stack->head;
        stack->head = new_node;
        stack->head->next = tmp_node;
        stack->head->prev = stack->tail;
        tmp_node->prev = new_node;
        stack->tail->next = stack->head;
    }
    stack->size += 1;
}

t_node *ft_pop_stack(t_stack *stack)
{
    t_node *node;

    if (stack && stack->size > 0)
    {
        node = stack->head;
        if (stack->size == 1)
        {
            stack->head = NULL;
            stack->tail = NULL;
            stack->min = 0;
            stack->max = 0;
        }
        else
        {
            stack->head = node->next;
            stack->head->prev = stack->tail;
            stack->tail->next = stack->head;
        }
        node->next = NULL;
        node->prev = NULL;
        stack->size--;
        return (node);
    }
    return (NULL);
}

t_stack *ft_create_stack()
{
    t_stack *new_stack;

    new_stack = (t_stack *)malloc(sizeof(t_stack));
    if (!new_stack)
        return (NULL);
    new_stack->head = NULL;
    new_stack->tail = NULL;
    new_stack->size = 0;
    new_stack->min = 0;
    new_stack->max = 0;
    return (new_stack);
}
