#include "libft.h"

int		ft_numlen(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		count++;
		n = n / 10;
	}
	return (count);
}
