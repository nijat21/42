int prime_helper(int nb, int guess)
{
    if (nb < 2)
        nb = 2;
    if (guess * guess > nb)
        return (nb);
    if (nb % guess == 0 && nb != guess)
        return prime_helper(nb + 1, guess);
    return prime_helper(nb, guess + 1);
}

int ft_find_next_prime(int nb)
{
    return (prime_helper(nb, 2));
}
/*
#include <stdio.h>

int main()
{
    printf("%i\n", ft_find_next_prime(6));
} */