#include "../ft_push_swap.h"

int     ft_binary_search(int *arr, int len, int value)
{
    int high = len - 1;
    int low = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value)
            return mid;
        if (arr[mid] <  value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return (-1);
}
