#include "printf.h"

char	*format_s(va_list ap)
{
	const char	*str;

	str = va_arg(ap, const char *);
	if (!str)
		return(ft_strdup((const char *)"(null)"));
	return(ft_strdup(str));
}

char	*format_c(t_arg *params, va_list ap)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = (unsigned char)va_arg(ap, unsigned int);
	params->length = 1;
	return(str);
}

char	*format_d(t_arg *params, va_list ap)
{
	int		n;

	n = (int)va_arg(ap, int);
	if (n < 0)
		params->neg = 1;
	return(ft_itoa(n));
}

char	*format_percent(void)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = '%';
	return(str);
}
