#include "printf.h"

char	*format_s(va_list ap)
{
	return(ft_strdup(va_arg(ap, const char *)));
}

char	*format_c(va_list ap)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = (unsigned char)va_arg(ap, unsigned int);
	return(str);
}

char	*format_d(va_list ap)
{
	return(ft_itoa((int)va_arg(ap, int)));
}

char	*format_percent(void)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = '%';
	return(str);
}
