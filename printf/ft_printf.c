#include "printf.h"

/*
** %[flags][width][.precision][length]specifier
** %c (int) -> (unsigned char)
** %s (const char *) -> write until '\0'
** %p (void *) -> hexadecimal
** %d %i (int) -> signed decimal integer
** %u (unsigned int) converted into unsigned decimal
** %x %X (unsigned int) converted into unsigned hexadecimal
** %% write '%'
*/

void	print_list(t_list *element, int *r)
{
	while (element)
	{
		ft_putstr((char *)element->content);
		*r += ft_strlen((const char *)element->content);
		element = element->next;
	}
}

void	clear_string(void *str)
{
	char	*s;

	s = (char *)str;
	ft_strdel(&s);
}

int		read_string(t_list **begin, const char *str, int i)
{
	t_list	*new;
	int		count;

	count = 0;
	while (str[i + count] && str[i + count] != '%')
		count++;
	new = ft_lstnew((void *)ft_substr(str, i, count));
	ft_lstadd_back(begin, new);
	return (i + count);
}

char	*isolate_format(const char *str, int i)
{
	int		count;
	char	c;

	count = 1;
	c = str[i + count];
	while (c && !(c == 'c' || c == 's' || c == 'p' || c == 'd'
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%'))
	{
		count++;
		c = str[i + count];
	}
	return (ft_substr(str, i, count + 1));
}

int		add_element_in_list(t_list **begin, char *str)
{
	t_list	*new;

	new = ft_lstnew((void *)str);
	if (!new)
		return (0);
	ft_lstadd_back(begin, new);
	return (1);
}

t_arg	*init_params(t_list **begin, char *format)
{
	t_arg	*new;

	new = (t_arg *)malloc(sizeof(t_arg));
	if (!new)
		return (NULL);
	new->flag_zero = 0;
	new->flag_minus = 0;
	new->mul = 0;
	new->width = 0;
	new->precision = 0;
	new->dot = 0;
	new->precision_mul = 0;
	new->length = 0;
	new->neg = 0;
	new->format = format[ft_strlen(format) - 1];
	new->list = begin;
	return (new);
}

int		update_params(t_arg *params, char c, int num)
{
	if (c == '0')
		params->flag_zero = num;
	else if (ft_isdigit(c))
		params->width = num;
	else if (c == '-')
		params->flag_minus = num;
	else if (c == '.')
	{
		params->dot = 1;
		params->precision = num;
	}
	else if (c == '*')
		params->mul = num;
	else
		return (0);
	return (1);
}

int		analyze_format(t_arg *params, char *format, va_list ap)
{
	int	i;
	int	num;
	int	zeroes;

	zeroes = 0;
	i = 1;
	while (format[i] && format[i] != params->format)
	{
		while (format[i + 1 + zeroes] && format[i + 1 + zeroes] == '0' && !(format[i] >= '1' && format[i] <= '9'))
			zeroes++;
		if (format[i] == '0' || format[i] == '-' || format[i] == '.')
			if (format[i + 1] == '*')
				num = (int)va_arg(ap, int);
			else if (format[i] == '-' && format[i + 1] == '-')
			{
				i++;
				continue ;
			}
			else if (ft_isdigit(format[i + 1]) || format[i] == '.')
				num = ft_atoi((const char *)&format[i + 1]);
			else
			{
				i++;
				continue ;
			}
		else if (ft_isdigit(format[i]))
			num = ft_atoi((const char *)&format[i]);
		else if (format[i] == '*')
			num = (int)va_arg(ap, int);
		else
			return (0);

		if (!update_params(params, format[i], num))
			return (0);
		if (format[i] == '*' || (format[i] >= '1' && format[i] <= '9'))
			i += ft_numlen(num) + zeroes;
		else
			i += ft_numlen(num) + 1 + zeroes;
	}
	return (1);
}


int		run_conversion(t_list **begin, char *format, va_list ap)
{
	t_arg	*params;

	params = init_params(begin, format);
	if (ft_strlen(format) > 2)
		if (!analyze_format(params, format, ap))
			return (0);
	if (!router(params, ap))
		return (0);
	return (1);
}

int		router_flags(t_arg *params, char **str)
{
	if (params->dot && params->precision == 0 && *str[0] == '0')
		ft_strclr(*str);
	if (params->precision > 0 && !(params->format == 'c' || params->format == 's' || params->format == '%') && params->neg)
		*str = flag_zero_neg(params, *str);
	if (params->precision > 0 && !(params->format == 'c' || params->format == 's' || params->format == '%'))
		*str = flag_zero(params, *str);
	if (params->dot && params->format == 's')
		*str = flag_zero_str(params, *str);
	if (params->width > 0 || params->mul > 0)
		*str = flag_width(params, *str);
	else if (params->flag_zero > 0 && params->neg)
		*str = flag_zero_neg(params, *str);
	else if (params->flag_zero > 0)
		*str = flag_zero(params, *str);
	else if (params->flag_minus > 0)
		*str = flag_minus(params, *str);
	return (1);
}

int		router(t_arg *params, va_list ap)
{
	char	*str;

	if (params->format == 's')
		str = format_s(ap);
	else if (params->format == 'd' || params->format == 'i')
		str = format_d(params, ap);
	else if (params->format == 'c')
		str = format_c(ap);
	else if (params->format == '%')
		str = format_percent();
	else if (params->format == 'u')
		str = format_u(ap);
	else if (params->format == 'x')
		str = format_x(ap);
	else if (params->format == 'X')
		str = format_X(ap);
	else if (params->format == 'p')
		str = format_p(ap);
	else
		return (0);
	router_flags(params, &str);
	if (add_element_in_list(params->list, str))
			return (1);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	t_list	*begin;
	va_list	args;
	char	*format;
	int		i;
	int		result;

	begin = NULL;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		i = read_string(&begin, str, i);
		if (str[i] == '%')
		{
			format = isolate_format(str, i);
			run_conversion(&begin, format, args);
			i += ft_strlen(format);
			free(format);
		}
	}
	va_end(args);
	result = 0;
	print_list(begin, &result);
	ft_lstclear(&begin, &clear_string);
	return (result);
}
