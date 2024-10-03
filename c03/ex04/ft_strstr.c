char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    if (!to_find[0])
        return str;
    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i + j] && str[i + j] == to_find[j])
        {
            if (!to_find[j + 1])
                return &str[i];
            j++;
        }
        i++;
    }
    return (0);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
    char *haystack = "Well world";
    char *needle = "wo";
    char *needle1 = "ol";

    char *res = strstr(haystack, needle);
    char *res1 = strstr(haystack, needle1);

    char *res_local = ft_strstr(haystack, needle);
    char *res_local1 = ft_strstr(haystack, needle1);

    printf("Original found: %s\n", res);
    printf("Original not found: %s\n", res1);

    printf("Mine found: %s\n", res_local);
    printf("Mine not found: %s\n", res_local1);
}
 */