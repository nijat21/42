#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "dict_entry.h"

int is_positive_num(const char *str);
int is_num(char c);
int is_name(char c);
int open_file(char *input_file);
int close_file(int dict);
dict_entry *read_alloc(char *input_file, int dict);

// static char *error_result[] = {"ERROR"};

// typedef struct
// {
//     char *number;
//     char *name;
// } dict_entry;

dict_entry *alloc_input_mem(char *input_file)
{
    int dict;
    dict_entry *table;

    dict = open_file(input_file);
    // if (dict == -1)
    //     return error_result;
    table = read_alloc(input_file, dict);
    // if (close_file(dict) == -1)
    //     return error_result;
    return table;
}

dict_entry *input_data(char *input_file)
{
    int dict;
    char buffer[1];
    int line_i;
    dict_entry *table;

    table = alloc_input_mem(input_file);
    dict = open_file(input_file);
    // if (dict == -1)
    //     return error_result;
    line_i = 0;
    while ((read(dict, buffer, 1)) > 0)
    {
        // mem[line_i][char_i] = buffer[0];
        if (is_num(buffer[0]))
        {
            table[line_i].number = &buffer[0];
        }
        else if (is_name(buffer[0]))
        {
            table[line_i].name = &buffer[0];
        }
        if (buffer[0] == '\n')
        {
            line_i++;
        }
    }
    // if (close_file(dict) == -1)
    //     return error_result;
    return table;
}

// char **input_data(char *input_file)
// {
//     int dict;
//     char buffer[1];
//     int char_count;
//     int line_i;
//     dict_entry *table;

//     table = alloc_input_mem(input_file);
//     dict = open_file(input_file);
//     if (dict == -1)
//         return error_result;
//     line_i = 0;
//     char_count = 0;
//     while ((read(dict, buffer, 1)) > 0)
//     {
//         mem[line_i][char_count] = buffer[0];
//         if (buffer[0] == '\n')
//         {
//             mem[line_i][char_count] = '\0';
//             line_i++;
//             char_count = 0;
//         }
//         else
//             char_count++;
//     }
//     if (close_file(dict) == -1)
//         return error_result;
//     return mem;
// }

int read_dict(void)
{
    dict_entry *table;
    char *input_file;

    input_file = "numbers.dict";

    table = input_data(input_file);
    // mem = alloc_input_mem(input_file);

    printf("%s\n", table[0].number);

    return (0);
}

// typedef struct
// {
//     char *number;
//     char *name;
// } dict_entry;

// dict_entry *save_dict(void)
// {
//     int i;
//     char *mem;
//     dict_entry *table;

//     table = (dict_entry *)malloc(900);
//     if (!table)
//     {
//         write(1, "Memory Error\n", 13);
//         return (0);
//     }
//     mem = read_dict();
//     i = 0;
//     while (mem[i])
//     {
//         table[0].number = malloc(37 * 4);
//         // printf("Char: %c\n", mem[i]);
//         if (mem[i] >= '0' && mem[i] <= '9')
//         {
//             table[0].number[i] = mem[i];
//         }
//         if (mem[i + 1] == ' ' || mem[i + 1] == ':')
//             table[0].number[i] = '\0';
//         i++;
//     }
//     printf("Number: %s\n", table[0].number);
//     return table;
// }

long double ten_powers(unsigned int n)
{
    unsigned int i;
    long double result;

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

int main(void)
{
    double n = ten_powers(10);
    printf("%f\n", n);

    // char *mem = read_dict();
    // printf("%s\n", mem);

    read_dict();

    return (0);
}