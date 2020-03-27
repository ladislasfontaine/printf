#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*data;

	data = malloc(size);
	if (data)
		ft_bzero(data, size);
	return (data);
}
