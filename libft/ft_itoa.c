#include "libft.h"

static int	num_len(long n)
{
	int	len;
	int	neg;

	len = 1;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		len;
	long	num;

	num = n;
	len = num_len(num);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	neg = 0;
	if (num < 0)
	{
		neg = 1;
		num = -num;
	}
	while (len > 0)
	{
		if (len == 1 && neg)
			str[0] = '-';
		else
			str[len - 1] = (num % 10) + 48;
		num = num / 10;
		len--;
	}
	return (str);
}
