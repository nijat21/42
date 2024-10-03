#include <unistd.h>

int is_safe(char *base)
{
    int i;
    int j;

    i = 0;
    while (base[i])
    {
        if (base[i] == '-' || base[i] == '+')
            return (0);
        j = 0;
        while (base[j] && (j != i))
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    if (i == 0 || i == 1)
        return (0);
    return (1);
}

int base_type(char *base)
{
    int i;
    int j;
    char *radix[] = {"0123456789", "01", "0123456789ABCDEF", "poneyvif"};

    j = 0;
    while (j < 4)
    {
        i = 0;
        while (base[i])
        {
            if (!radix[j][i] || (unsigned char)base[i] != (unsigned char)radix[j][i])
            {
                i++;
                continue;
            }
            i++;
        }
        if (base[i] == '\0')
            return i;
        j++;
    }
    return 0;
}

void ft_putnbr_base(int nbr, char *base)
{
    char c;
    int bt;

    if (!is_safe(base))
        return;
    if (!(-2147483648 <= nbr && nbr <= 2147483647))
        return;
    bt = base_type(base);
    if (nbr < 0)
    {
        write(1, "-", 1);
        if (nbr == -2147483648)
        {
            ft_putnbr_base(-(nbr / bt), base);
            char e = base[(8 % bt)];
            write(1, &e, 1);
            return;
        }
        nbr = -nbr;
    }
    if (nbr >= bt)
        ft_putnbr_base(nbr / bt, base);

    c = base[(nbr % bt)];
    write(1, &c, 1);
}
/*
#include <stdio.h>

int main(void)
{
    char *radix_dec = "0123456789";       //-2147483648
    char *radix_bi = "01";                // -10000000000000000000000000000000
    char *radix_hex = "0123456789ABCDEF"; // -80000000
    char *radix_oct = "poneyvif";         // -npppppppppp

    // int n = base_type(radix_oct);
    // printf("%i\n", n);

    ft_putnbr_base(-2147483648, radix_oct);
}
 */