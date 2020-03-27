#include "libft.h"

void	ft_putnbr(int n)
{
	long	num;
	char	c;

	num = n;
	if (n < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	c = num % 10 + 48;
	write(1, &c, 1);
}