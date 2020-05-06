/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lafontai <lafontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:52:57 by lafontai          #+#    #+#             */
/*   Updated: 2020/05/06 08:11:04 by lafontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		analyze_format(t_arg *params, char *format, va_list ap)
{
	int	i;
	int	num;
	int	zeroes;
	int	star;

	i = 1;
	while (format[i] && format[i] != params->format)
	{
		zeroes = 0;
		star = 0;
		if (format[i] == '0' || format[i] == '-' || format[i] == '.')
			if (format[i + 1] == '*')
			{
				num = (int)va_arg(ap, int);
				star = 1;
			}
			else if (ft_isdigit(format[i + 1]) || format[i] == '.')
			{
				num = ft_atoi((const char *)&format[i + 1]);
				while (num != 0 && format[i + 1 + zeroes] &&
						format[i + 1 + zeroes] == '0')
					zeroes++;
			}
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
		if (format[i] == '*')
			i += 1 + zeroes;
		else if (format[i] >= '1' && format[i] <= '9')
			i += ft_numlen(num) + zeroes;
		else if (star)
			i += 2 + zeroes;
		else if (format[i] == '.' && !ft_isdigit(format[i + 1]))
			i += 1 + zeroes;
		else
			i += ft_numlen(num) + 1 + zeroes;
	}
	return (1);
}

int		run_conversion(t_list **begin, char *format, va_list ap)
{
	t_arg	*params;

	params = init_params(begin, format);
	if (ft_strlen(format) < 2 ||
		(ft_strlen(format) > 2 && !analyze_format(params, format, ap)))
	{
		free(params);
		return (0);
	}
	if (!router(params, ap))
	{
		free(params);
		return (0);
	}
	free(params);
	return (1);
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
