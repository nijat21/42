#include <stdio.h>
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int count;
    unsigned int count_src;
    unsigned int i;

    count = 0;
    while (dest[count])
        count++;
    count_src = 0;
    while (src[count_src])
        count_src++;
    printf("total: %i\n", (count + count_src));
    if (size == 0 || count >= size)
        return count_src + size;
    i = 0;
    while (src[i] != '\0' && i < size - count - 1)
    {
        dest[count + i] = (unsigned char)src[i];
        i++;
    }
    dest[count + i] = '\0';
    return (count + count_src);
}
/*
#include <string.h>

int main(void)
{
    char s1[15] = "1337 42";
    char s2[] = "Born to code";
    char s3[15] = "1337 42";
    unsigned int size = 7;

    int res1 = strlcat(s1, s2, size);
    int res2 = ft_strlcat(s3, s2, size);

    printf("Original: %s\n", s1);
    printf("Original: %i\n", res1);
    printf("Mine: %s\n", s3);
    printf("Mine: %i\n", res2);

    char s5[15] = "1337 42";
    char s4[] = "Born to code";
    char s6[15] = "1337 42";
    unsigned int size1 = 6;

    int res3 = strlcat(s4, s4, size1);

    int res4 = ft_strlcat(s6, s4, size1);

    printf("Original: %s\n", s1);
    printf("Original: %i\n", res3);
    printf("Mine: %s\n", s3);
    printf("Mine: %i\n", res4);
}
 */