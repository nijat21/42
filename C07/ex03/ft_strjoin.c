#include <stdlib.h>

int ft_strlen(char *str)
{
    int count;

    count = 0;
    while (str[count])
        count++;
    return count;
}

int total_len(char **str)
{
    int t_len;

    t_len = 0;
    while (*str)
    {
        t_len += ft_strlen(*str);
        str++;
    }
    return t_len;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i;
    int j;
    // int f;
    char *res;

    res = NULL;
    if (size == 0)
    {
        *res = '\0';
        return res;
    }
    res = malloc(total_len(strs) + (size - 1) * sizeof(sep) + 1);
    i = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j])
        {
            res[j] = strs[i][j];
            // f = 0;
            // while (sep[f])
            // {
            //     res[j + f] = sep[f];
            //     f++;
            // }
            j++;
        }
        i++;
    }
    return res;
}

#include <stdio.h>

int main()
{
    char *str1 = "Good";
    char *str2 = "boy";
    char *str3 = "Diego";
    char *str[] = {str1, str2, str3, NULL};

    char **strstr = str;

    // int res = total_len(strstr);
    char *res = ft_strjoin(3, strstr, "HAV");
    printf("%s\n", res);
}