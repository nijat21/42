#include <unistd.h>

void char_to_hex(char ch, char hex[3])
{
    const char *hex_digits = "0123456789abcdef";
    hex[0] = hex_digits[(ch >> 4) & 0xF]; // Get the higher nibble
    hex[1] = hex_digits[ch & 0xF];        // Get the lower nibble
    hex[2] = '\0';                        // Null-terminate the string
}

void ft_putstr_non_printable(char *str)
{
    int i;
    char c;
    char hex[3];

    i = 0;
    while (str[i] != '\0')
    {
        if (!(32 <= str[i] && str[i] <= 126))
        {
            char_to_hex(str[i], hex);
            write(1, &hex, 1);
        }
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(void)
{
    char *str = "Coucou\0tu vas bien ?";
    ft_putstr_non_printable(str);

    return (0);
}