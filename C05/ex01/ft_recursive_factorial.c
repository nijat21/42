int ft_recursive_factorial(int nb)
{
    int temp;

    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (1);
    return (nb * ft_recursive_factorial(nb - 1));
}
/*
#include <stdio.h>

int main()
{
    int res = ft_recursive_factorial(0); // 1,2,3,4
    printf("Res: %i\n", res);
}
 */