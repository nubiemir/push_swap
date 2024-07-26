#ifndef FT_SWAP_H
#define FT_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct node *next;
    struct node *prev;
    int data;
    int binary[32];
} t_node;

typedef struct stack
{
    t_node *head;
    t_node *tail;
    int min;
    int max;
    int size;
} t_stack;

#define True 1
#define False 0
#define t_bool int

t_stack     *ft_create_stack();
void        ft_push_stack(t_stack *stack, t_node *new_node);
t_node      *ft_create_node(int data, int binary[32]);
t_node      *ft_pop_stack(t_stack *stack);
void        ft_push_a(t_stack *stack_a, t_stack *stack_b);
void        ft_push_b(t_stack *stack_a, t_stack *stack_b);
void        ft_swap_a(t_stack *stack);
void        ft_swap_b(t_stack *stack);
void        ft_swap(t_stack *stack);
void        ft_rotate_a(t_stack *stack);
void        ft_rotate_b(t_stack *stack);
void        ft_rotate(t_stack *stack);
void        ft_rev_rotate_a(t_stack *stack);
void        ft_rev_rotate_b(t_stack *stack);
void        ft_rev_rotate(t_stack *stack);
void        safe_free(void **ptr);
t_stack     *ft_push_swap(int *arr, t_stack *stack_a, t_stack *stack_b);
t_stack     *ft_stack_of_three(t_stack *stack);
t_bool      ft_check_sorted(t_stack *stack);
void        ft_find_min(t_stack *stack);
void        ft_find_max(t_stack *stack);
void        ft_populate_stack_a(t_stack *stack_a, t_stack *stack_b);
void        ft_populate_stack_b(int *arr, t_stack *stack_a, t_stack *stack_b);
int         *ft_quick_sort(int *arr, int len);
int         ft_binary_search(int *arr, int len, int value);
void        ft_to_binary(int arr[32], int num);
int         ft_max_digit(t_stack *stack);

#endif
