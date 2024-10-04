int in_base(char c, char *base)
{
    int i;

    i = 0;
    while (base[i])
    {
        if (c == base[i])
            return (1);
        i++;
    }
    return (0);
}

int prefix_check(char c, char *base)
{
    if (in_base(c, base) ||
        (c == '-') || (c == '+') ||
        (c == ' '))
        return (1);
    else
        return (0);
}

int base_check(char *base)
{
    int i;
    int j;

    i = 0;
    while (base[i])
    {
        if (base[i] == '-' || base[i] == '+')
            return 0;
        j = 0;
        while (base[j] && j != i)
        {
            if (base[j] == base[i])
                return (0);
            j++;
        }
        i++;
    }
    if (i == 0 || i == 1)
        return (0);
    return i;
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

int find_index(char c, char *base)
{
    int i;

    i = 0;
    while (base[i])
    {
        if (c == base[i])
            return i;
        i++;
    }
    return (0);
}

int calculate(char *arr, int radix, int len, char *base)
{
    int i;
    int result;
    // printf("arr: %s\n", arr);
    // printf("radix: %i\n", radix);
    // printf("len: %i\n", len);

    i = 0;
    result = 0;
    while (i < len)
    {
        result += find_index(arr[i], base) * num_powers(radix, len - 1 - i);
        i++;
    }
    return result;
}

int ft_atoi_base(char *str, char *base)
{
    int i;
    int len;
    int radix;
    char arr[32];

    if (!(radix = base_check(base)))
        return (0);
    i = 0;
    len = 0;
    while (str[i])
    {
        if (in_base(str[i], base))
        {
            arr[len] = str[i];
            len++;
            if ((i - 1 >= 0) && !prefix_check(str[i - 1], base))
                break;
            if ((str[i + 1] != '\0') && !in_base(str[i + 1], base))
                break;
        }
        i++;
    }
    return det_sign(str) * calculate(arr, radix, len, base);
}
/*
#include <stdio.h>

int main(void)
{
    // char *str = " ---+-+ABsome123";
    // char *str = " ---+-+123ABsome";
    // char *str = "some-123AFaf";
    // char *str = "FF";
    // char *str = " -123some";
    char *str = "101101";

    // char *base = "0123456789ABCDEF";
    // char *base = "0123456789";
    char *base = "01";

    int res = ft_atoi_base(str, base);

    printf("%i\n", res);

    int res1 = in_base('0', base);
    printf("In base: %i\n", res1);

    return (0);
} */