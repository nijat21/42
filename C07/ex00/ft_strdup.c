#include <stdlib.h>

int ft_strlen(char *str)
{
    int count;

    count = 0;
    while (str[count])
        count++;
    return count;
}

char *ft_strdup(char *src)
{
    char *ptr;
    char *start;

    ptr = malloc(ft_strlen(src) + 1);
    if (!ptr)
        return NULL;
    start = ptr;
    while (*src)
    {
        *ptr = *src;
        src++;
        ptr++;
    }
    *ptr = '\0';
    return start;
}
/*
#include <stdio.h>

int main()
{
    char *str = "Some";

    char *res = ft_strdup(str);
    printf("%s\n", res);
} */