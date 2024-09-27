char *ft_strcapitalize(char *str)
{
    int i;

    i = 0;
    while (str[i] != 0)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] = str[i] + 32;
        if (('a' <= str[i] && str[i] <= 'z') &&
            ((i == 0) ||
             (32 <= str[i - 1] &&
              str[i - 1] <= 47 &&
              i >= 0)))
        {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return str;
}
/*
#include <stdio.h>

int main(void)
{
    char source[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    char check[] = "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un";

    char *result = ft_strcapitalize(source);

    printf("Output: %s\n", result);
    printf("Check: %s\n", check);

    return 0;
}
 */