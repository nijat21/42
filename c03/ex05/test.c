unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int dest_len;
    unsigned int src_len;
    unsigned int i;

    dest_len = 0;
    while (dest[dest_len])
        dest_len++;
    src_len = 0;
    while (src[src_len])
        src_len++;
    if (size == 0 || dest_len > size)
        return (dest_len + size + 1);

    i = 0;
    while (dest[i] && i < size - dest_len - 1)
    {
    }
}