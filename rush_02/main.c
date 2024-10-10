#include <unistd.h>

int is_positive_num(const char *str)
{
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
        {
            write(1, "Error\n", 6);
            return (0);
        }
        str++;
    }
    return (1);
}

int main(int ac, char *av[])
{
    if (!(ac > 1 && ac < 4))
        return (0);
    else if (ac == 2)
    {
        if (is_positive_num(av[1]))
        {
            write(1, "Error\n", 6);
            return (0);
        }
        // call the function
    }
    else
    {
        if (is_positive_num(av[2]))
        {
            write(1, "Error\n", 6);
            return (0);
        }
        // call the function
        return (0);
    }
    return (0);
}