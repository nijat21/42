#include <stdlib.h>
#include <stdio.h>

int ft_atoi(const char *str)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (str[i] != '\0')
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            if ((i >= 0) && ((str[i - 1] == '-') || (str[i - 1] == '+')))
            {

            }
            num = num * 10 + (str[i] - '0');
        }
    }
    return num;
}

int main(void)
{
    char *str = "-123absolute";
    int result = atoi(str);
    printf("%i\n", result);

    return (0);
}