#include "ft_push_swap.h"
#include <stdio.h>

void print(int arr[32]) {
    for (int i = 0; i < 32; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    t_stack *stack_a = ft_create_stack();
    t_stack *stack_b = ft_create_stack();
    int sorted[10];

    int initial[] = {8, 4, 9, 3, 6, 1, 7, 2, 5, 10};

    for (int i = 0; i <= 9; i++)
        sorted[i] = initial[i];

    ft_quick_sort(sorted, 10);

    for (int i = 0; i <= 9; i++)
    {
        int binary[32];
        int data = ft_binary_search(sorted, 10, initial[i]) + 1;
        ft_to_binary(binary, data);
        t_node *node = ft_create_node(data, binary);
        ft_push_stack(stack_a, node);
    }

    while (stack_a->head &&  stack_a->head->data != stack_a->tail->data)
    {
        print(stack_a->head->binary);
        printf("%d\n", stack_a->head->data);
        stack_a->head = stack_a->head->next;
    }

    print(stack_a->head->binary);
    printf("%d\n", stack_a->head->data);

    // printf("###################################\n");
    //
    // while (stack_b->head && stack_b->head->data != stack_b->tail->data)
    // {
    //     printf("%d\n", stack_b->head->data);
    //     stack_b->head = stack_b->head->next;
    // }
    // printf("%d\n", stack_b->head->data);
}
