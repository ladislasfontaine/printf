#include "printf/printf.h"
#include <stdio.h>

int		main(void)
{
	int	n = 96;
	//char *n = "b";

	ft_printf("%x and %X AND %p\n", 153000, 0, &n);
	printf("%x and %X AND %p\n", 153000, 0, &n);
	return (0);
}
