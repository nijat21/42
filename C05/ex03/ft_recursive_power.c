int ft_recursive_power(int nb, int power)
{
    int temp;

    if (power < 0)
        return (0);
    if (power == 0 && nb == 0)
        return (1);
    temp = nb;
    if (power > 0)
        ft_recursive_power(nb, power - 1);
    temp *= nb;
    return temp;
}

#include <stdio.h>

int main(void)
{
    int res = ft_recursive_power(1, 2);
    int res1 = ft_recursive_power(0, 0);
    int res2 = ft_recursive_power(2, 3);
    int res3 = ft_recursive_power(2, 4);

    printf("%i\n", res);
    printf("%i\n", res1);
    printf("%i\n", res2);
    printf("%i\n", res3);
}