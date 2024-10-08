int ft_iterative_factorial(int nb)
{
    int temp;

    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (1);
    temp = 1;
    while (nb > 0)
    {
        temp *= nb;
        nb--;
    }
    return temp;
}
/*
#include <stdio.h>

int main(void)
{
    int res = ft_iterative_factorial(2);
    int res1 = ft_iterative_factorial(3);
    int res2 = ft_iterative_factorial(1);

    printf("%i\n", res);
    printf("%i\n", res1);
    printf("%i\n", res2);

    return (0);
} */