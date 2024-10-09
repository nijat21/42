int prime_helper(int nb, int guess)
{
    if (guess * guess > nb)
        return (1);
    if (nb % guess == 0 && nb != guess)
        return (0);
    return prime_helper(nb, guess + 1);
}

int ft_is_prime(int nb)
{
    if (nb < 2)
        return (0);
    return (prime_helper(nb, 2));
}
/*
#include <stdio.h>

int main()
{
    printf("%i\n", ft_is_prime(13));
} */