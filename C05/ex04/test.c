
#include <stdio.h>
int fib(int index)
{
    int i = 0;
    int res = 0;

    while (index > 1)
    {
        printf("%i %i\n", res, i);
        res = res + i;
        i++;
        index--;
    }
    return res;
}

int main()
{
    int res = fib(3);
    printf("%i\n", res);
    return (0);
}