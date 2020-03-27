#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		dst_len;
	size_t	i;

	dst_len = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[dst_len + i] = s2[i];
		i++;
	}
	s1[dst_len + i] = '\0';
	return (s1);
}
