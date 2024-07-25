#include "../ft_push_swap.h"

void    ft_to_binary(int arr[32], int num)
{
    for (int i = 31; i >= 0; i--) {
        int mask = (1 << i);
        if (num & mask)
           arr[31 - i] = 1;
        else
            arr[31 - i] = 0;
}                                                                                    }
