#include "get_next_line.h"

void create_merge(char *buffer, int *index, char **final_line)
{
    char *new_line;
    char *temp_line;

    new_line = make_line(buffer, index);
    if (!new_line)
    {
        free(*final_line);
        *final_line = NULL;
        return;
    }
    temp_line = ft_strjoin(*final_line, new_line);
    free(new_line);
    free(*final_line);
    if (!temp_line)
    {
        *final_line = NULL;
        free(temp_line);
        return;
    }
    *final_line = temp_line;
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    int bytes_read;
    char *nl;
    int index;

    nl = NULL;
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
        create_merge(buf, &index, &nl);
        if (!nl)
            break;
        printf("Index: %i\n", index);
        ft_strcpy(buf, &buf[index]);
        if (nl[ft_strlen(nl) - 1] == '\n')
            break;
    }
    return nl;
}

// SOME ISSUE IN UPDATING THE BUFFER WHEN BUFFER_SIZE IS 10
// Hello$
// Franky, $
// the $
// stupidest$
// goast,$
// st$

// BUFFER INCLUDES SEVERAL NEW LINES
// BUFFER IS SMALLER THAN THE INDEX OF '\n'

// POSSIBLE SCENARIOS
// READ A BUFFER AND FIND '\n' AND RETURN
// LEFTOVER BUFFER SHOULD BE READ IN THE NEXT FUNC CALL IF ANY
// READ SEVERAL BUFFERS BEFORE YOU FIND '\n' AND RETURN
// LEFTOVER BUFFER SHOULD BE READ IN THE NEXT FUNC CALL IF ANY
// READ SEVERAL BUFFERS UNTIL THE END OF THE FILE AND DON'T FIND '\n'

// INSTEAD OF HAVING index AS STATIC, UPDATE BUF IF NEW LINE OR END OF IT