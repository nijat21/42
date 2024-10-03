#include <unistd.h>

void ft_putnbr(int nb)
{
    if (-2147483648 <= nb && nb <= 2147483647)
    {
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
    int i = 108;
    ft_putnbr(i);
    return (0);
} */