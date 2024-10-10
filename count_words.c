#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

bool is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(const char *str)
{
    int count = 0;
    bool in_word = false;

    while (*str)
    {
        if (!is_space(*str))
        {
            if (!in_word)
            { // Start of a new word
                count++;
                in_word = true;
            }
        }
        else
        {
            in_word = false; // Outside of a word
        }
        str++;
    }

    return count;
}

int main(void)
{
    char *str = " some                   Hello\n                 world.            some";

    printf("%i\n", count_words(str));

    return (0);
}