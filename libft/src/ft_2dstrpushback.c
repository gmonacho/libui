#include "../includes/libft.h"
#include <stdio.h>

char		**ft_2dstrpushback(char **tab, int size_i, const char *line)
{
	char    **ntab;
	int	    i;

	if (!(ntab = (char**)ft_memalloc(sizeof(char*) * (size_i + 2))))
		return (NULL);
	i = 0;
	if (tab)
	{
		while (i < size_i)
		{
			if (!(ntab[i] = ft_strdup(tab[i])))
				return (NULL); // LEAKS
			i++;
		}
	}
	if (!(ntab[i++] = ft_strdup(line)))
		return (NULL); // LEAKS
	ntab[i] = NULL;
	return (ntab);
}