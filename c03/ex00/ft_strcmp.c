int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] || s2[i])
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
    char *s1 = "something";
    char *s2 = "some";

    char *s3 = "some";
    char *s4 = "soms";

    char *s5 = "some";
    char *s6 = "some";

    char *s7 = "s";
    char *s8 = "";

    printf("Original: %i\n", strcmp(s1, s2));
    printf("Mine: %i\n", ft_strcmp(s1, s2));

    printf("Original: %i\n", strcmp(s3, s4));
    printf("Mine: %i\n", ft_strcmp(s3, s4));

    printf("Original: %i\n", strcmp(s5, s6));
    printf("Mine: %i\n", ft_strcmp(s5, s6));

    printf("Original: %i\n", strcmp(s7, s8));
    printf("Mine: %i\n", ft_strcmp(s7, s8));

    return (0);
} */