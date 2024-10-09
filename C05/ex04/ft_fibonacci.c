#include <stdio.h>

int ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    if (index == 0)
        return (0);
    printf("Index: %i\n", index);

    return ((index - 1) + ft_fibonacci(index - 2));
}

int main()
{
    int res = ft_fibonacci(3);
    printf("Result: %i\n", res);

    return (0);
}