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

int num_powers(int num, int power)
{
    int i;
    int result;

    i = 0;
    if (power == 0)
        return (1);
    result = 1;
    while (i < power)
    {
        result *= num;
        i++;
    }
    return result;
}

int valid_base(char *base)
{
    int i;
    int j;

    i = 0;
    while (base[i])
    {
        if (base[i] == '-' || base[i] == '+')
            return (0);
        j = 0;
        while (base[j] && (j != i))
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    if (i == 0 || i == 1)
        return (0);
    return i;
}

int convert_arr(int *arr, int count, char *base)
{
    int i;
    int res;
    int num;

    if (count == 0)
        return (0);
    num = valid_base(base);
    i = 0;
    res = 0;
    while (i < count)
    {
        res += arr[i] * num_powers(10, count - 1 - i);
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

int ft_atoi_base(char *str, char *base)
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
    return convert_arr(arr, count, base) * det_sign(str);
}

// #include <stdio.h>

// int main(void)
// {
//     char *str = " ---+--+1234ab567";
//     // char *str = " ---+--+abc123";
//     // char *str = "1234ab567";
//     // char *str = "-1234ab567";

//     char *radix_hex = "0123456789ABCDEF";

//     int res1 = ft_atoi_base(str, radix_hex);

//     printf("Mine: %i\n", res1);

//     return (0);
// }