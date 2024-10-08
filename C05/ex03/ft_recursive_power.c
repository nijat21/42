#include <stdio.h>
int ft_recursive_power(int nb, int power)
{
    // int temp;

    if (power < 0)
        return (0);
    if (power == 0 || (power == 0 && nb == 0))
        return (1);
    if (power == 1)
        return nb;
    return (nb * ft_recursive_power(nb, power - 1));
}
/*
int main(void)
{
    // int res = ft_recursive_power(1, 2);
    int res1 = ft_recursive_power(0, 1);
    // int res2 = ft_recursive_power(2, 3);
    // int res3 = ft_recursive_power(2, 4);

    printf("%i\n", res1);
} */