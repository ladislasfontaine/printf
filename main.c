#include "stdio.h"
#include "printf/printf.h"

int		main(void)
{
	char	*name = "Lad";
	//char	*name2 = "Johny";
	//int		age = 2456;

	ft_printf("Bonjour à tous\n", name);
	printf("Bonjour %s aminches\n", name);
	return (0);
}