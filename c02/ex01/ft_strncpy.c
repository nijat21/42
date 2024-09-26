char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    // If src is longer than dest, it will copy len chars without '\0' at the end
    // If src is shorter than dest, it will fill rest with '\0's
    int i;

    if (n == 0)
        return dest;
    i = 0;
    while (i < n)
    {
        if (src[i] == '\0')
        {
            while (i < n)
            {
                dest[i] = '\0';
                i++;
            }
            break;
        }
        else
            dest[i] = src[i];
        i++;
    }
    return dest;
}
/*
#include <stdio.h>

int main(void)
{
    char *source = "Nicat";
    char dest[12];
    int len = 12;

    char *result = ft_strncpy(dest, source, len);

    // printf("%s\n", result);
    // printf("%s\n", dest);

    // Check if '\0' is added at the end
    int i = 0;
    while (i < len)
    {
        printf("%c", dest[i]);
        i++;
    }

    // // When memory is bigger than needed will see some trash values
    // for (int i = 0; i < 12; i++)
    // {
    //     printf("%c", dest[i]);
    // }

    return 0;
}
*/