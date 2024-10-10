#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *ptr;
    int diff;
    int i;

    if (min >= max)
        return NULL;
    diff = max - min;
    ptr = malloc(diff * sizeof(int));
    if (!ptr)
        return NULL;
    i = 0;
    while (i < diff)
    {
        ptr[i] = min;
        min++;
        i++;
    }
    return ptr;
}
/*
#include <stdio.h>

int main()
{
    int *res = ft_range(1, 5);
    int i = 0;
    while (i < 4)
    {
        printf("%i\n", res[i]);
        i++;
    }
} */