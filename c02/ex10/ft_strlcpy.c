unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	// If src is longer than dest, it will copy len - 1 chars with '\0' at the end
	// If src is shorter than dest, it will copy only the src with '\0' at the end
	int src_len;
	int i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return src_len;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
	char *source = "Nicat";
	char dest[3];
	char dest1[3];
	int len = 3;
	int len1 = 3;

	int result = ft_strlcpy(dest, source, len);
	int result1 = strlcpy(dest1, source, len1);

	printf("Solution return: %i\n", result);
	printf("Solution dest: %s\n", dest);
	printf("Original return: %i\n", result1);
	printf("Original dest: %s\n", dest1);

	// // When memory is bigger than needed will see some trash values
	// for (int i = 0; i < 12; i++)
	// {
	//     printf("%c", dest[i]);
	// }

	return 0;
}
