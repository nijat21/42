#include <unistd.h>

void ft_pustr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

int main(int ac, char *av[])
{
    int i;

    if (ac == 1)
        return (0);
    i = ac - 1;
    while (i > 0)
    {
        ft_pustr(av[i]);
        i--;
    }
}