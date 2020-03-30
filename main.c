#include "stdio.h"
#include "printf/printf.h"

int		main(void)
{
	char	*name = "Lad";
	//char	*name2 = "Johny";
	int		age = 4;
	int		age2 = 99;
	int		age3 = 5;

	ft_printf("Bonjour %4.6s a%%nd %4.3d @@niiiice %*.*d %2c tous\n", name, age, age3, age, age2, 'Z');
	printf("Bonjour %4.6s a%%nd %4.3d @@niiiice %*.*d %2c tous\n", name, age, age3, age, age2, 'Z');
	//getchar();
	return (0);
}