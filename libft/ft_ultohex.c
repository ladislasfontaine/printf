#include "libft.h"

static int	hex_len(unsigned long n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*ft_ultohex(unsigned long n, char *base)
{
	char			*str;
	int				len;

	len = hex_len(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (len > 0)
	{
		str[len - 1] = base[n % 16];
		n = n / 16;
		len--;
	}
	return (str);
}