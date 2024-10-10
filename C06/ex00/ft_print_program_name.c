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
    (void)ac;
    ft_pustr(av[0]);
}