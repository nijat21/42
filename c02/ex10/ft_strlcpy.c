unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    // If src is longer than dest, it will copy len - 1 chars with '\0' at the end
    // If src is shorter than dest, it will copy only the src with '\0' at the end
    int i;
    int src_length;
    int concluded;

    src_length = 0;
    while (src[src_length] != '\0')
        src_length++;
    if (size == 0)
        return src_length;
    i = 0;

    dest[i] = src[i];

    return src_length;
}

#include <stdio.h>

int main(void)
{
    char *source = "Nicat";
    char dest[12];
    int len = 12;

    int result = ft_strlcpy(dest, source, len);

    printf("%i\n", result);
    printf("%s\n", dest);

    // // When memory is bigger than needed will see some trash values
    // for (int i = 0; i < 12; i++)
    // {
    //     printf("%c", dest[i]);
    // }

    return 0;
}
