#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int diff;
    int i;

    if (min >= max)
    {
        *range = NULL;
        return (0);
    }
    diff = max - min;
    *range = (int *)malloc(diff * sizeof(int));
    if (!*range)
        return (-1);
    i = 0;
    while (i < diff)
    {
        range[0][i] = min;
        min++;
        i++;
    }
    return (i);
}
/*
    int **ptr = 0x1 => {0x10, 0x11...}
    int *ptr = 0x10 = {1, 2, 3, 4}
    int *ptr = 0x11 = {1, 2, 3, 4}
*/
/* #include <stdio.h>

int main()
{
    int *arr = NULL;
    int min = 0;
    int max = 0;
    int len = max - min;

    int res = ft_ultimate_range(&arr, min, max);
    printf("Res %i\n", res);
    int i = 0;
    while (i < len)
    {
        printf("%d\n", arr[i]);
        i++;
    }
} */