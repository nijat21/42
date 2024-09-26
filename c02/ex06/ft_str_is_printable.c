int ft_str_is_printable(char *str)
{
    int i;
    int result;

    i = 0;
    if (str[0] == '\0')
        return (1);
    while (str[i] != '\0')
    {
        if (!(32 <= str[i] && str[i] <= 127))
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
    char *source = "Hello\x06";

    int result = ft_str_is_printable(source);

    printf("%i\n", result);

    return 0;
}
 */