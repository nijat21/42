int sqrt_helper(int nb, int guess)
{
    if (guess * guess == nb)
        return guess;
    else if (guess * guess > nb)
        return (0);
    return sqrt_helper(nb, guess + 1);
}

int ft_sqrt(int nb)
{
    if (nb < 0)
        return (0);
    return sqrt_helper(nb, 0);
}
/*
#include <stdio.h>

int main()
{
    int res = ft_sqrt(3);
    printf("%i\n", res);
} */