#include "printf.h"

char	*flag_zero(t_arg *params, char *arg)
{
	int		i;
	int		diff;
	int		flag;
	char	*new;

	flag = (params->flag_zero > params->precision) ? params->flag_zero : params->precision;
	diff = flag - ft_strlen(arg);
	if (diff > 0)
	{
		new = ft_strnew(flag);
		i = 0;
		while (i < diff + params->neg)
		{
			new[i] = '0';
			i++;
		}
		ft_strcat(new, (const char *)arg);
		free(arg);
		return (new);
	}
	else
		return (arg);
}

char	*flag_zero_neg(t_arg *params, char *arg)
{
	int		i;
	int		diff;
	int		flag;
	char	*new;

	flag = (params->flag_zero > params->precision) ? params->flag_zero : params->precision + 1;
	diff = flag - ft_strlen(arg);
	if (diff > 0)
	{
		new = ft_strnew(flag);
		new[0] = '-';
		i = 1;
		while (i < (diff + params->neg))
		{
			new[i] = '0';
			i++;
		}
		ft_strcat(new, (const char *)(arg + 1));
		free(arg);
		return (new);
	}
	else
		return (arg);
}

char	*flag_zero_str(t_arg *params, char *arg)
{
	int		diff;
	size_t	max_len;
	char	*new;

	max_len = params->precision;
	diff = max_len - ft_strlen(arg);
	if (diff < 0)
	{
		new = ft_strnew(max_len);
		ft_strncpy(new, (const char *)arg, max_len);
		free(arg);
		return (new);
	}
	else
		return (arg);
}

char	*flag_minus(t_arg *params, char *arg)
{
	int		i;
	int		diff;
	char	*new;

	diff = params->flag_minus - ft_strlen(arg);
	if (diff > 0)
	{
		i = ft_strlen(arg);
		new = ft_strnew(params->flag_minus);
		ft_strcpy(new, (const char *)arg);
		free(arg);
		while (i < params->flag_minus)
		{
			new[i] = ' ';
			i++;
		}
		return (new);
	}
	return (arg);
}

char	*flag_width(t_arg *params, char *arg)
{
	int		i;
	int		diff;
	int		flag;
	char	*new;

	flag = (params->width > 0) ? params->width : params->mul;
	diff = flag - ft_strlen(arg);
	if (diff > 0)
	{
		i = 0;
		new = ft_strnew(flag);
		while (i < diff)
		{
			new[i] = ' ';
			i++;
		}
		ft_strcat(new, (const char *)arg);
		free(arg);
		return (new);
	}
	return (arg);
}