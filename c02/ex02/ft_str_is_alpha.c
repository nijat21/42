int ft_str_is_alpha(char *str)
{
    int i;
    int result;

    i = 0;
    if (str[0] == '\0')
        return (1);
    while (str[i] != '\0')
    {
        if (!(('A' <= str[i] && str[i] <= 'Z') ||
              ('a' <= str[i] && str[i] <= 'z')))
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
    char *source = "s";

    int result = ft_str_is_alpha(source);

    printf("%i\n", result);

    return 0;
}
 */