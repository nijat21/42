#include "get_next_line.h"

int ft_strlen(char *str)
{
    int count;

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

    len = ft_strlen(str);
    *index = len;
    new_line = malloc(len + 1);
    i = 0;
    while (i < len && str[i])
    {
        new_line[i] = str[i];
        i++;
    }
    new_line[i] = '\0';
    return new_line;
}

char *merge_lines(char *prev_line, char *curr_line)
{
    char *final_line;
    int i;
    int j;

    final_line = malloc(ft_strlen(prev_line) + ft_strlen(curr_line) + 1);
    i = 0;
    while (prev_line[i])
    {
        final_line[i] = prev_line[i];
        i++;
    }
    j = 0;
    while (curr_line[j])
    {
        final_line[i + j] = curr_line[j];
        j++;
    }
    final_line[i + j] = '\0';
    return final_line;
}

// LEFTOVER BUFFER
char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    int bytes_read;
    char *new_line;
    char *final_line;
    int index;

    final_line = NULL;
    bytes_read = 0;
    while (bytes_read >= 0)
    {
        index = 0;
        if (!buf[index])
        {
            bytes_read = read(fd, buf, BUFFER_SIZE);
            if (bytes_read <= 0)
                break;
            buf[BUFFER_SIZE] = '\0';
        }
        new_line = make_line(buf, &index);
        ft_strcpy(buf, &buf[index]);
        if (new_line[ft_strlen(new_line) - 1] == '\n')
            break;
    }
    return new_line;
}

// BUFFER INCLUDES SEVERAL NEW LINES
// BUFFER IS SMALLER THAN THE INDEX OF '\n'

// POSSIBLE SCENARIOS
// READ A BUFFER AND FIND '\n' AND RETURN
// LEFTOVER BUFFER SHOULD BE READ IN THE NEXT FUNC CALL IF ANY
// READ SEVERAL BUFFERS BEFORE YOU FIND '\n' AND RETURN
// LEFTOVER BUFFER SHOULD BE READ IN THE NEXT FUNC CALL IF ANY
// READ SEVERAL BUFFERS UNTIL THE END OF THE FILE AND DON'T FIND '\n'

// INSTEAD OF HAVING index AS STATIC, UPDATE BUF IF NEW LINE OR END OF IT