#include "printf/printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%.8s and %.32s\n", NULL, "hello there");
	printf("%.8s and %.32s\n", NULL, "hello there");
	return (0);
}
