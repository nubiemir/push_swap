#include "../ft_push_swap.h"

void safe_free(void **ptr)
{
    if (ptr == NULL)
        return;
    free(*ptr);
    *ptr = NULL;
}

t_bool ft_check_sorted(t_stack *stack)
{
    t_node *ptr;

    ptr = stack->head;
    while (ptr->data != stack->tail->data)
    {
        if (ptr->data - ptr->next->data > 0)
            return (False);
        ptr = ptr->next;
    }

    return (True);
}

void ft_find_min(t_stack *stack)
{
    t_node *ptr;
    int idx;
    int min;

    ptr = stack->head;
    min = ptr->data;
    idx = 0;
    while (idx < stack->size)
    {
        ptr = ptr->next;
        if (min > ptr->data)
            min = ptr->data;
        idx++;
    }
    stack->min = min;
}

void ft_find_max(t_stack *stack)
{
    t_node *ptr;
    int idx;
    int max;

    ptr = stack->head;
    max = ptr->data;
    idx = 0;
    while (idx < stack->size)
    {
        ptr = ptr->next;
        if (max < ptr->data)
            max = ptr->data;
        idx++;
    }
    stack->max = max;
}

t_chosen *ft_create_chosen()
{
    t_chosen *chosen_node;

    chosen_node = (t_chosen *)malloc(sizeof(t_chosen));
    if (!chosen_node)
        return (NULL);
    chosen_node->position_a = -1;
    chosen_node->position_b = -1;
    return (chosen_node);
}