char *ft_strcat(char *dest, char *src)
{
    int count;
    int j;

    count = 0;
    while (dest[count])
        count++;
    j = 0;
    while (src[j] != '\0')
    {
        dest[count + j] = (unsigned char)src[j];
        j++;
    }
    dest[count + j] = '\0';
    return dest;
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
    char s1[15] = "some";
    char s2[] = "where";

    char *res1 = strcat(s1, s2);

    char s3[15] = "some";
    char s4[] = "where";

    char *res2 = ft_strcat(s3, s4);

    printf("Original: %s\n", s1);
    printf("Original: %s\n", res1);
    printf("Mine: %s\n", s3);
    printf("Mine: %s\n", res2);
} */