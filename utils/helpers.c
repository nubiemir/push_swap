#include "../ft_push_swap.h"
#include <stdio.h>


int  ft_max_digit(t_stack *stack)
{
    int i;
    int max;
    t_node *tmp_node;
    t_node *result;

    tmp_node = stack->head;
    max = 0;
    i = 0;
    while (i <= stack->size - 1)
    {
        if (tmp_node->data > max)
        {
            max = tmp_node->data;
            result = tmp_node;
        }
        tmp_node = tmp_node->next;
        i++;
    }

    i = 0;
    while (i++ <= 31) {
        if (result->binary[i] == 1)
            return (32 - i);
    }
    return (32 - i);
}

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
