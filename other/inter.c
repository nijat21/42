#include <stdio.h>

int is_match(char c, char *str)
{
    while (*str)
    {
        if (*str == c)
            return (1);
        str++;
    }
    return (0);
}

int ft_strlen(char *str)
{
    int count = 0;

    while (*str)
    {
        count++;
        str++;
    }
    return count;
}

void unique_list(char *str, char *str2)
{
    int i = 0, ind = 0;
    char arr[ft_strlen(str)];

    while (str[i])
    {
        if (!is_match(str[i], arr) && is_match(str[i], str2))
        {
            arr[ind] = str[i];
            ind++;
        }
        i++;
    }
    arr[ind] = '\0';
    printf("%s\n", arr);
}

int main()
{
    char *str1 = "abcdce";
    char *str2 = "acdbcahmte";
    unique_list(str1, str2);
}