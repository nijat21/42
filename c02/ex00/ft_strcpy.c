char *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
/*
#include <stdio.h>

int main(void)
{
    char *source = "Nicat";
    char dest[12];

    char *result = ft_strcpy(dest, source);

    printf("%s\n", result);
    // printf("%s\n", dest);

    // // Check if '\0' is added at the end
    // int i = 0;
    // while (dest[i] != '\0')
    // {
    //     printf("%c", dest[i]);
    //     i++;
    // }

    // // When memory is bigger than needed will see some trash values
    // for (int i = 0; i < 12; i++)
    // {
    //     printf("%c", dest[i]);
    // }

    return 0;
}
*/