unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int count;
    unsigned int j;

    count = 0;
    while (dest[count])
        count++;
    j = 0;
    while (src[j] != '\0' && j < nb)
    {
        dest[count + j] = (unsigned char)src[j];
        j++;
    }
    dest[count + j] = '\0';
    return dest;
}

#include <string.h>
#include <stdio.h>

int main(void)
{
    char s1[15] = "some";
    char s2[] = "where";
    unsigned int size = 5;

    char *res1 = strncat(s1, s2, size);

    char s3[15] = "some";
    char s4[] = "where";

    char *res2 = ft_strncat(s3, s4, size);

    printf("Original: %s\n", s1);
    printf("Original: %s\n", res1);
    printf("Mine: %s\n", s3);
    printf("Mine: %s\n", res2);
}
