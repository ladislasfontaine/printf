#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*element;

	element = *alst;
	if (!element)
	{
		*alst = new;
		return ;
	}
	while (element && element->next)
		element = element->next;
	element->next = new;
}
