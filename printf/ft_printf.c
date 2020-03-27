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

int		ft_printf(const char *str, ...)
{
	t_list	*begin;
	va_list	args;
	//char	*var;
	int		i;

	// check nombre d'arguments
	// check validité des args %
	begin = NULL;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		i = read_string(&begin, str, i);
		//if (str[i] == '%')
		//	read_conversion()		
	}
		/*
		while (str[i])
		{
			if (str[i] == '%' && str[i + 1] == 's')
			{
				var = (char *)va_arg(args, const char *);
				ft_putstr(var);
				i++;
			}
			else
				ft_putchar(str[i]);
			i++;
			// i = read(&begin, str, i);

		}
		*/
		// lire str
		// si on rencontre un % -> ft_substr -> détermine le type de conversion (gestion des flags plus tard)
		// on essaye de lire args avec le type de var correspondant à la conversion
		// on appelle une fonction pour conversion (en lui donnant une liste) pour y ajouter la conversion en char * (ft_itoa)

	va_end(args);

	print_list(begin);
	ft_lstclear(&begin, &clear_string);
	// on affiche les éléments de la liste un à un
	// on clear la liste

	return (0);
}
