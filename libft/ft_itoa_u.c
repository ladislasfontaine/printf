/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lafontai <lafontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 08:40:56 by lafontai          #+#    #+#             */
/*   Updated: 2020/05/05 09:19:42 by lafontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_u(unsigned int n)
{
	char			*str;
	int				neg;
	int				len;
	unsigned int	num;

	num = n;
	len = ft_numlen(num);
	if (!(str = ft_strnew(len)))
		return (NULL);
	neg = 0;
	if (num < 0)
	{
		neg = 1;
		num = -num;
	}
	while (len > 0)
	{
		if (len == 1 && neg)
			str[0] = '-';
		else
			str[len - 1] = (num % 10) + 48;
		num = num / 10;
		len--;
	}
	return (str);
}
