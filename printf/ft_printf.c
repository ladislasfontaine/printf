#include "printf.h"

/*
** %[flags][width][.precision][length]specifier

%

** c (int) -> (unsigned char)
** s (const char *) -> write until '\0'
** p (void *) -> hexadecimal
** d, i (int) -> signed decimal integer
** u (unsigned int) converted into unsigned decimal
** x, X (unsigned int) converted into unsigned hexadecimal
** % write '%'
** '-0.*' different flags to manage
** minimal size
*/
/*
int		router()
{}

// tableau avec les différentes fonctions pour les différents arguments
*/

void	print_list(t_list *element)
{
	while (element)
	{
		ft_putstr((char *)element->content);
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
	while (c && !(c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%'))
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
/*
int		read_conversion(t_list **begin, char *format, va_list ap)
{
	int		len;
	char	*str;

	len = ft_strlen(format);
	if (len == 2 && format[1] == 's')
	{
		str = ft_strdup(va_arg(ap, const char *));
		if (add_element_in_list(begin, str))
			return (1);
	}
	return (0);
}
*/
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
	new->precision_mul = 0;
	new->length = 0;
	new->format = format[ft_strlen(format) - 1];
	new->list = begin;
	return (new);
}

int		analyze_format(t_arg *params, char *format, va_list ap)
{
	int	i;
	int	num;

	i = 1;
	while (format[i])
	{
		if (format[i] == '0' || format[i] == '-' || format[i] == '.')
			if (format[i + 1] == '*')
				num = (int)va_arg(ap, int);
			else
				num = ft_atoi((const char *)&format[i + 1]);
		else if (ft_isdigit(format[i]))
			num = ft_atoi((const char *)&format[i]);
		else if (format[i] == '*')
			num = (int)va_arg(ap, int);

		// new function update_params(t_arg *params, char format[i], int num)
		if (format[i] == '0')
			params->flag_zero = num;
		else if (ft_isdigit(format[i]))
			params->width = num;
		else if (format[i] == '-')
			params->flag_minus = num;
		else if (format[i] == '.')
			params->precision = num;
		else if (format[i] == '*')
			params->mul = num;
		else
			return (0);

		if (!num)
			return (0);
		if (format[i] == '*' || (format[i] >= '1' && format[i] <= '9'))
			i += ft_numlen(num);
		else
			i += ft_numlen(num) + 1;
		if (format[i] == params->format)
			return (1);
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

int		router(t_arg *params, va_list ap)
{
	char	*str;

	// conversions
	if (params->format == 's')
		str = format_s(ap);
	else if (params->format == 'd' || params->format == 'i')
		str = format_d(ap);
	else if (params->format == 'c')
		str = format_c(ap);
	else if (params->format == '%')
		str = format_percent();
	else
		return (0);
	// flags
	if (params->precision > 0 && (params->format == 'd' || params->format == 'i'))
		str = flag_zero(params, str);
	if (params->width > 0 || params->mul > 0)
		str = flag_width(params, str);
	else if (params->flag_zero > 0)
		str = flag_zero(params, str);
	else if (params->flag_minus > 0)
		str = flag_minus(params, str);

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

	// check nombre d'arguments
	// check validité des args %
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
	print_list(begin);
	ft_lstclear(&begin, &clear_string);
	return (0);
}
