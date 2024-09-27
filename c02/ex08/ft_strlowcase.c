char *ft_lowcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return str;
}
/*
#include <stdio.h>

int main(void)
{
    char source[] = "EVERY LETTER";

    char *result = ft_lowcase(source);

    printf("%s\n", result);

    return 0;
}
 */