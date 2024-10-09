int ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    if (index < 2)
        return index;
    return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
// fib(6)
// fib(5) + fib(4)
// fib(1) + fib(0)
/* #include <stdio.h>

int main()
{
    int res = ft_fibonacci(2); // 0, 1, 1, 2, 3, 5, 8, 13
    printf("Result: %i\n", res);

    return (0);
} */