int ft_srt_is_numeric(char *str)
{
    int i;
    int result;

    i = 0;
    if (str[0] == '\0')
        return (1);
    while (str[i] != '\0')
    {
        if (!('0' <= str[i] && str[i] <= '9'))
        {
            result = 0;
            break;
        }
        else
            result = 1;
        i++;
    }
    return result;
}
/*
#include <stdio.h>

int main(void)
{
    char *source = "125s";

    int result = ft_srt_is_numeric(source);

    printf("%i\n", result);

    return 0;
}
 */