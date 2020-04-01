#include "printf/printf.h"
#include <stdio.h>

int		main(void)
{
	int	n = 96;

	ft_printf("%06.5i and %X AND %p\n", 34, 0, &n);
	printf("%06.5i and %X AND %p\n", 34, 0, &n);
	return (0);
}
