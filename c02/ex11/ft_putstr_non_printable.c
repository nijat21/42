#include <unistd.h>

void char_to_hex(char ch)
{
    const char *hext_digits = "0123456789abcdef";
    char result[2];

    result[0] = hext_digits[ch / 16];
    result[1] = hext_digits[ch % 16];

    write(1, &result, 2);
}

void ft_putstr_non_printable(char *str)
{
    int i;
    char *hex;

    i = 0;
    while (str[i] != '\0')
    {
        if (!(32 <= str[i] && str[i] <= 126))
        {
            char_to_hex(str[i]);
        }
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(void)
{
    char *str = "Coucou\ntu vas bien ?";
    ft_putstr_non_printable(str);

    return (0);
}