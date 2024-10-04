int ten_powers(int n)
{
    int i;
    int result;

    i = 0;
    if (n == 0)
        return (1);
    result = 1;
    while (i < n)
    {
        result *= 10;
        i++;
    }
    return result;
}

int det_sign(char *str)
{
    int i;
    int j;
    int count;

    i = 0;
    while (str[i])
    {
        if ((str[i] >= '0' && str[i] <= '9'))
            break;
        i++;
    }
    count = 0;
    j = 0;
    while (j < i)
    {
        if (str[j] == '-')
            count++;
        j++;
    }
    if (count % 2 == 1)
        return (-1);
    else
        return (1);
}

int convert_arr(int *arr, int count)
{
    int i;
    int res;

    if (count == 0)
        return (0);
    i = 0;
    res = 0;
    while (i < count)
    {
        res += arr[i] * ten_powers(count - 1 - i);
        i++;
    }
    return res;
}

int is_safe(char c)
{
    if ((c >= '0' && c <= '9') ||
        (c == '-') || (c == '+') ||
        (c == ' '))
        return (1);
    else
        return (0);
}

int ft_atoi(char *str)
{
    int i;
    int count;
    int arr[10];

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (!is_safe(str[i - 1]) && i > 0)
                break;
            arr[count] = str[i] - '0';
            count++;
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9') &&
                (str[i + 1] != '\0'))
                break;
        }
        i++;
    }
    return convert_arr(arr, count) * det_sign(str);
}
/*
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // char *str = " ---+--+1234ab567";
    // char *str = " ---+--+abc123";
    // char *str = "1234ab567";
    // char *str = "-1234ab567";
    char *str = "some-123";

    int res1 = ft_atoi(str);

    printf("Mine: %i\n", res1);

    // int sign = det_sign(str);
    // printf("Sign: %i\n", sign);

    return (0);
} */