#include "printf.h"

char	*format_u(va_list ap)
{
	unsigned int	n;

	n = (unsigned int)va_arg(ap, int);
	return (ft_itoa_u(n));
}

char	*format_x(va_list ap)
{
	return (ft_itohex((unsigned int)va_arg(ap, int), "0123456789abcdef"));
}

char	*format_X(va_list ap)
{
	return (ft_itohex((unsigned int)va_arg(ap, int), "0123456789ABCDEF"));
}

char	*format_p(va_list ap)
{
	unsigned long	addr;
	char	*str;
	char	*hex;

	addr = va_arg(ap, unsigned long);
	hex = ft_ultohex(addr, "0123456789abcdef");

	if (!addr)
		str = ft_strdup((const char *)"0x0");
	else
	{
		str = ft_strnew(ft_strlen(hex) + 2);
		ft_strcpy(str, (const char *)"0x");
		ft_strcat(str, (const char *)hex);
	}
	return (str);
}
