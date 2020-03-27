#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*element;
	t_list	*delete;

	element = *lst;
	while (element)
	{
		delete = element;
		element = element->next;
		(*del)(delete->content);
		free(delete);
	}
	*lst = NULL;
}
