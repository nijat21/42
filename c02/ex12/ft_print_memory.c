#include <unistd.h>
#include <stdint.h>

void print_hex(char ch)
{
    const char *hex_digits = "0123456789abcdef";
    char result[2];

    result[0] = hex_digits[ch / 16];
    result[1] = hex_digits[ch % 16];

    write(1, &result, 2);
}

void print_ascii(unsigned char *str, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        if (32 <= str[i] && str[i] <= 126)
            write(1, &str[i], 1);
        else
            write(1, ".", 1);
        i++;
    }
}

void print_address(uintptr_t addr)
{
    char hex[16];
    int i;

    i = 15;
    while (i >= 0)
    {
        hex[i] = "0123456789abcdef"[addr % 16];
        addr /= 16;
        i--;
    }
    write(1, hex, 16);
}

void print_line(uintptr_t addr, unsigned char *mem, unsigned int size)
{
    unsigned int i;

    print_address(addr);
    write(1, ":", 1);
    write(1, " ", 1);

    i = 0;
    while (i < 16)
    {
        if (i < size)
            print_hex(mem[i]);
        else
            write(1, "  ", 2);
        if (i % 2)
            write(1, " ", 1);
        i++;
    }

    print_ascii(mem, size);
    write(1, "\n", 1);
}

void *ft_print_memory(void *addr, unsigned int size)
{
    unsigned int i;
    uintptr_t base_addr = (uintptr_t)addr;
    unsigned char *mem = (unsigned char *)addr;
    unsigned int line_size;

    if (size == 0)
        return (0);
    i = 0;
    while (i < size)
    {
        if (size - i < 16)
            line_size = size - i;
        else
            line_size = 16;
        print_line(base_addr + i, mem + i, line_size);
        i += 16;
    }
    return addr;
}
/*
#include <stdio.h>

int main(void)
{
    char test_string[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\tprint_memory\n\tlol.lol.\0";
    unsigned int size = sizeof(test_string) - 1;

    ft_print_memory(test_string, size);

    return (0);
} */