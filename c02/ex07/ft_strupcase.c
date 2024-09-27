char *ft_strupcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if ('a' <= str[i] && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return str;
}
/*
#include <stdio.h>

int main(void)
{
    char source[] = "every letter";

    char *result = ft_strupcase(source);

    printf("%s\n", result);

    return 0;
}
 */