#include <unistd.h>

void *ft_print_memory(void *addr, unsigned int size)
{
    int max_length;
    char *str;
    int i;

    max_length = 16;
    if (size == 0)
        return (0);
    i = 0;
    while (str[i])
    {
        if (!(32 <= str[i] && str[i] <= 126))
            str[i] = ".";
    }

    return addr;
}

int main(void)
{
    char **str =
        return (0);
}