#include <unistd.h>

void ft_pustr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
/*
int main(void)
{
    char *str = "42 rocks";

    ft_pustr(str);
    return (0);
} */