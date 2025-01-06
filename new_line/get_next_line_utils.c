#include "get_next_line.h"

int ft_strlen(char *str)
{
    int count;

    if (!str)
        return 0;
    count = 0;
    while (str[count] && str[count] != '\n')
        count++;
    if (str[count] == '\n')
        count++;
    return count;
}

void ft_strcpy(char *des, char *src)
{
    int i;

    if (!src)
        return;
    i = 0;
    while (src[i])
    {
        des[i] = src[i];
        i++;
    }
    des[i] = '\0';
    while (des[i++])
        des[i] = '\0';
    return;
}

char *make_line(char *str, int *index)
{
    char *new_line;
    int len;
    int i;

    if (!str)
        return NULL;
    len = ft_strlen(str);
    *index = len;
    new_line = malloc(len + 1);
    if (!new_line)
        return NULL;
    i = 0;
    while (i < len && str[i])
    {
        new_line[i] = str[i];
        i++;
    }
    new_line[i] = '\0';
    return new_line;
}

char *ft_strjoin(char *prev_line, char *curr_line)
{
    char *final_line;
    int i;
    int j;

    final_line = malloc(ft_strlen(prev_line) + ft_strlen(curr_line) + 1);
    if (!final_line)
        return NULL;
    i = 0;
    if (prev_line)
        while (prev_line[i])
        {
            final_line[i] = prev_line[i];
            i++;
        }
    j = 0;
    if (curr_line)
        while (curr_line[j])
        {
            final_line[i + j] = curr_line[j];
            j++;
        }
    final_line[i + j] = '\0';
    return final_line;
}