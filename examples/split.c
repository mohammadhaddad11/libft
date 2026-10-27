#include "libft.h"
#include <stdlib.h>

int	main(void)
{
	char	**words;
	size_t	i;

	words = ft_split("memory,pointers,ownership", ',');
	if (!words)
		return (1);
	i = 0;
	while (words[i])
	{
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
