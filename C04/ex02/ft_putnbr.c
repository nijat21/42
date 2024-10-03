#include <unistd.h>

void ft_putnbr(int nb)
{
    if (-2147483648 <= nb && nb <= 2147483647)
    {
        if (nb == -2147483648)
        {
            write(1, "-2147483648", 11);
            return;
        }
        if (nb < 0)
        {
            nb = -nb;
            write(1, "-", 1);
        }
        if (nb >= 10)
        {
            ft_putnbr(nb / 10);
        }
        char c = (nb % 10) + '0';
        write(1, &c, 1);
    }
}
/*
int main(void)
{
    int i = -2147483648;
    // int i = 2147483647;
    ft_putnbr(i);
    return (0);
} */