/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 10:00:53 by marvin            #+#    #+#             */
/*   Updated: 2020/03/27 10:06:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_arg
{
	int		flag_zero;
	int		flag_minus;
	int		mul;
	int		width;
	int		precision;
	int		dot;
	int		precision_mul;
	int		length;
	int		neg;
	char	format;
	t_list	**list;
}				t_arg;


int		ft_printf(const char *, ...);
// parse str
int		read_string(t_list **begin, const char *str, int i);

char	*isolate_format(const char *str, int i);
//int		read_conversion(t_list **begin, char *format, va_list ap);
int		run_conversion(t_list **begin, char *format, va_list ap);
t_arg	*init_params(t_list **begin, char *format); // mettre tous les params à 0 + adresse de la liste + lettre du format
int		analyze_format(t_arg *params, char *format, va_list ap); // remplir les diff params en fonction des flags if len > 2
int		update_params(t_arg *params, char c, int num);
// tableau de pointeurs sur fonction OU if et else if
int		router(t_arg *params, va_list ap); // pour appeler la bonne fonction + les options ensuite
int		router_flags(t_arg *params, char **str);

char	*format_c(va_list ap); // return NULL en cas d'erreur
char	*format_s(va_list ap);
char	*format_d(t_arg *params, va_list ap);
char	*format_u(va_list ap);
char	*format_p(va_list ap);
char	*format_x(va_list ap);
char	*format_X(va_list ap);
char	*format_percent(void);
		//etc
char	*flag_zero(t_arg *params, char *arg);
char	*flag_zero_neg(t_arg *params, char *arg);
char	*flag_zero_str(t_arg *params, char *arg);
char	*flag_minus(t_arg *params, char *arg);
char	*flag_width(t_arg *params, char *arg);

int		add_element_in_list(t_list **begin, char *str);

// print and clear
void	print_list(t_list *element, int *r);
void	clear_string(void *str);

#endif
