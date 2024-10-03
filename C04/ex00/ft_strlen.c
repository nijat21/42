int ft_strlen(char *str)
{
    unsigned int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

#include <stdio.h>

int main(void)
{
    char *str = "";

    int i = ft_strlen(str);
    printf("%i\n", i);
}