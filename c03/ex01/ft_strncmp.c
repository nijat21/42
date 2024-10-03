int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;

    i = 0;
    while ((s1[i] || s2[i]) && (i < n))
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned int n = 4;

    char *s1 = "soms";
    char *s2 = "some";

    char *s3 = "someÇ";
    char *s4 = "somsÇ";

    char *s5 = "some";
    char *s6 = "some";

    char *s7 = "";
    char *s8 = "";

    printf("Original: %i\n", strncmp(s1, s2, n));
    printf("Mine: %i\n", ft_strncmp(s1, s2, n));

    printf("Original: %i\n", strncmp(s3, s4, n));
    printf("Mine: %i\n", ft_strncmp(s3, s4, n));

    printf("Original: %i\n", strncmp(s5, s6, n));
    printf("Mine: %i\n", ft_strncmp(s5, s6, n));

    printf("Original: %i\n", strncmp(s7, s8, n));
    printf("Mine: %i\n", ft_strncmp(s7, s8, n));

    return (0);
} */