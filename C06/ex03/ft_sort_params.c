#include <unistd.h>

void ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 || *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (0);
}

void ft_swap(char **p1, char **p2)
{
    char *temp;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort_av(int ac, char *av[])
{
    int i;
    int j;

    if (ac == 2)
        ft_putstr(av[1]);
    j = 1;
    while (j < ac - 1)
    {
        i = 1;
        while (i < ac - 1)
        {
            if (ft_strcmp(av[i], av[i + 1]) > 0)
            {
                ft_swap(&av[i], &av[i + 1]);
            }
            i++;
        }
        j++;
    }
}

int main(int ac, char *av[])
{
    if (ac == 1)
        return (0);
    sort_av(ac, av);
    av++;
    while (*av)
    {
        ft_putstr(*av);
        av++;
    }
}