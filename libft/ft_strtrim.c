#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		total_len;
	int		before;
	int		after;

	total_len = ft_strlen(s1);
	before = 0;
	after = 0;
	while (s1[before] && ft_strchr(set, (int)s1[before]))
		before++;
	while (total_len - 1 - after >= 0 && ft_strchr(set, (int)s1[total_len - 1 - after]))
		after++;
	if (before + after >= total_len)
			return (ft_substr(s1, 0, 0));
	return (ft_substr(s1, before, total_len - before - after));
}
