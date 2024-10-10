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

int is_num(char c)
{
    if (!(c >= '0' && c <= '9'))
    {
        return (0);
    }
    return (1);
}

int is_name(char c)
{

    if (c >= 33 && c <= 126 && !is_num(c) && c != ' ' && c != ':')
    {
        return (1);
    }
    return (0);
}
