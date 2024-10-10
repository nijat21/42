#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

// Functions: write, malloc, free, open, read, close
double ft_atoi(char *str);

// int count_digs(double n)
// {
//     int count;

//     if (n < 0)
//         n = -n;
//     count = 0;
//     while (n > 9)
//     {
//         count++;
//         n /= 10;
//     }
//     return count;
// }

typedef struct
{
    int *number;
    char *name;
} dict_entry;

int count_chars(void)
{
    int dict;
    int sz;
    char buffer[1];
    int char_count = 0;

    dict = open("numbers.dict", O_RDONLY);
    if (dict == -1)
    {
        write(1, "Dict Error\n", 11);
        return (0);
    }
    while ((sz = read(dict, buffer, 1)) > 0)
    {
        char_count++;
    }
    printf("Char count: %i\n", char_count);
    if (close(dict) == -1)
    {
        write(1, "Dict Error\n", 11);
        return (0);
    }
    return char_count;
}

char *read_dict(void)
{
    int size;
    int dict;
    char *mem;

    // Allocate memory
    size = count_chars();
    mem = (char *)malloc(size);
    // Open the dictionary
    dict = open("numbers.dict", O_RDONLY);
    if (dict == -1)
    {
        write(1, "Dict Error\n", 11);
        return (0);
    }
    read(dict, mem, size);
    printf("%s\n", mem);
    // Close the dictionary
    if (close(dict) == -1)
    {
        write(1, "Dict Error\n", 11);
        return (0);
    }
    return mem;
}

dict_entry *save_dict(void)
{
    char *mem;
    dict_entry *table;

    mem = read_dict();
    while (*mem)
    {
        if (*mem >= '0' && *mem <= '9')
        {
            table->number = *mem;
        }
        mem++;
    }
}

int main(void)
{
    // double digits = 2147483648;
    double digits = -(double)(1.000000000000000042e+36);
    double digs = ft_atoi("99999999999999999999999999999999999");

    printf("%f\n", digs);
}