int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}

int c_words(char *str)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (!is_space(*str))
        {
            if (!in_word)
            {
                count++;
                in_word = 1;
            }
        }
        else
        {
            in_word = 0;
        }
        str++;
    }
    return count;
}

#include <stdio.h>

int main(int ac, char *av[])
{
    (void)ac;
    printf("%i\n", c_words(av[1]));
}