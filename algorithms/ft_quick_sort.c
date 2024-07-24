
#include "../ft_push_swap.h"

void    ft_arr_swap(int *arr, int idx1, int idx2)
{
    int tmp;

    tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int     ft_partition(int *arr, int low, int high)
{
    int idx;
    int counter;
    int pivot;

    pivot = arr[high];
    idx = low - 1;
    counter = low;
    while (counter < high)
    {
        if (arr[counter] < pivot)
            ft_arr_swap(arr, ++idx, counter);
        ++counter;
    }
    ++idx;
    ft_arr_swap(arr, idx, high);
    return idx;
}

void    qs(int *arr, int low, int high)
{
    int pivot;

    if (low >=high)
        return;
    pivot = ft_partition(arr, low, high);
    qs(arr, low, pivot - 1);
    qs(arr, pivot + 1, high);
}



int    *ft_quick_sort(int *arr, int len)
{
    qs(arr, 0, len - 1);
    return arr;
}
