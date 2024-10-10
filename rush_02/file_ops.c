#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "dict_entry.h"

int is_positive_num(const char *str);
int is_num(char c);
int is_name(char c);

int open_file(char *input_file)
{
    int dict;

    dict = open(input_file, O_RDONLY);
    if (dict == -1)
        write(1, "Dict Error\n", 11);
    return dict;
}

int close_file(int dict)
{
    if (close(dict) == -1)
    {
        write(1, "Dict Error\n", 11);
        return (-1);
    }
    return (0);
}

int count_chars(char *input_file)
{
    int dict;
    char buffer[1];
    int char_count = 0;

    dict = open(input_file, O_RDONLY);
    if (dict == -1)
    {
        write(1, "Dict Error\n", 11);
        return (0);
    }
    while ((read(dict, buffer, 1)) > 0)
    {
        char_count++;
    }
    if (close(dict) == -1)
    {
        write(1, "Dict Error\n", 11);
        return (0);
    }
    return char_count;
}

ssize_t safe_read(int dict, char *buffer, size_t count)
{
    ssize_t bytes_read = read(dict, buffer, count);
    if (bytes_read == -1)
        write(1, "Dict Error\n", 11);
    return bytes_read;
}

// typedef struct
// {
//     char *number;
//     char *name;
// } dict_entry;

dict_entry *read_alloc(char *input_file, int dict)
{
    int line_i;
    int num_i;
    int char_i;
    char buffer[1];
    int bytes_read;
    dict_entry *table;

    table = (dict_entry *)malloc(count_chars(input_file));
    line_i = 0;
    num_i = 0;
    char_i = 0;
    while ((bytes_read = safe_read(dict, buffer, 1)) > 0)
    {
        if (is_num(buffer[0]))
        {
            num_i++;
        }
        else if (is_name(buffer[0]))
        {
            char_i++;
        }
        if (buffer[0] == '\n')
        {
            table[line_i].number = (char *)malloc(num_i);
            table[line_i].name = (char *)malloc(char_i);
            line_i++;
            num_i = 0;
            char_i = 0;
        }
    }
    // if (bytes_read == -1)
    // return error_result;
    return table;
}

// char **read_alloc(char *input_file, int dict, char **error_result)
// {
//     int line_i;
//     int num_i;
//     int char_i;
//     char **mem;
//     char buffer[1];
//     int bytes_read;

//     mem = (char **)malloc(count_chars(input_file));
//     line_i = 0;
//     num_i = 0;
//     char_i = 0;
//     while ((bytes_read = safe_read(dict, buffer, 1)) > 0)
//     {

//         if (buffer[0] == '\n')
//         {
//             mem[line_i] = (char *)malloc(char_i);
//             line_i++;
//             char_i = 0;
//         }
//         else
//             char_i++;
//     }
//     if (bytes_read == -1)
//         return error_result;
//     return mem;
// }