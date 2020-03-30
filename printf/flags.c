#include "printf.h"

char	*flag_zero(t_arg *params, char *arg)
{
	int		i;
	int		diff;
	int		flag;
	char	*new;

	i = 0;
	if (params->flag_zero > 0)
		flag = params->flag_zero;
	else
		flag = params->precision;
	diff = flag - ft_strlen(arg);
	if (diff > 0)
	{
		new = ft_strnew(flag);
		while (i < diff)
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
	else
		return (arg);
}

char	*flag_width(t_arg *params, char *arg)
{
	int		i;
	int		diff;
	int		flag;
	char	*new;

	if (params->width > 0)
		flag = params->width;
	else
		flag = params->mul;
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
	else
		return (arg);
}