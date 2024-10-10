double ten_powers(unsigned int n)
{
    unsigned int i;
    double result;

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

int convert_arr(unsigned int *arr, unsigned int count)
{
    unsigned int i;
    double res;

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
        (c == ' '))
        return (1);
    else
        return (0);
}

double ft_atoi(char *str)
{
    unsigned int i;
    unsigned int count;
    unsigned int arr[36];

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
    return convert_arr(arr, count);
}