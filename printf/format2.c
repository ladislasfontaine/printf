#include "printf.h"

char	*format_u(va_list ap)
{
	return(ft_itoa((unsigned int)va_arg(ap, int)));
}

char	*format_p(va_list ap);
char	*format_x(va_list ap);
char	*format_X(va_list ap);
