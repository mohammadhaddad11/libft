#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	*copy_content(void *value)
{
	return (ft_strdup(value));
}

static char	upper(unsigned int index, char c)
{
	(void)index;
	return ((char)ft_toupper(c));
}

int	main(void)
{
	char	a[32];
	char	b[32];
	char	*text;
	char	**parts;
	t_list	*list;
	t_list	*mapped;
	int		i;
	int		numbers[5] = {INT_MIN, -42, 0, 42, INT_MAX};
	char	expected[32];

	i = 0;
	while (i <= 127)
	{
		assert(!!ft_isalpha(i) == !!isalpha(i));
		assert(!!ft_isdigit(i) == !!isdigit(i));
		assert(!!ft_isalnum(i) == !!isalnum(i));
		assert(!!ft_isprint(i) == !!isprint(i));
		assert(ft_toupper(i) == toupper(i));
		assert(ft_tolower(i) == tolower(i));
		i++;
	}
	memcpy(a, "0123456789", 11);
	memcpy(b, a, 11);
	ft_memmove(a + 2, a, 8);
	memmove(b + 2, b, 8);
	assert(memcmp(a, b, 11) == 0);
	ft_memmove(a, a + 2, 8);
	memmove(b, b + 2, 8);
	assert(memcmp(a, b, 11) == 0);
	assert(ft_memcmp("\xff", "\x01", 1) > 0);
	memcpy(a, "abc", 4);
	assert(ft_memchr(a, 'b', 3) == a + 1);
	assert(ft_strlcpy(a, "abcdef", 4) == 6);
	assert(strcmp(a, "abc") == 0);
	assert(ft_strlcat(a, "def", sizeof(a)) == 6);
	assert(strcmp(a, "abcdef") == 0);
	assert(ft_strnstr(a, "cd", 6) == a + 2);
	text = ft_calloc(8, 1);
	assert(text != NULL);
	assert(memcmp(text, "\0\0\0\0\0\0\0", 8) == 0);
	free(text);
	text = ft_strtrim("  memory\t", " \t");
	assert(text && strcmp(text, "memory") == 0);
	free(text);
	text = ft_strjoin("point", "ers");
	assert(text && strcmp(text, "pointers") == 0);
	free(text);
	text = ft_strmapi("memory", upper);
	assert(text && strcmp(text, "MEMORY") == 0);
	free(text);
	parts = ft_split(",one,,two,", ',');
	assert(parts && !strcmp(parts[0], "one") && !strcmp(parts[1], "two"));
	assert(parts[2] == NULL);
	free(parts[0]);
	free(parts[1]);
	free(parts);
	i = 0;
	while (i < 5)
	{
		snprintf(expected, sizeof(expected), "%d", numbers[i]);
		text = ft_itoa(numbers[i]);
		assert(text && strcmp(text, expected) == 0);
		assert(ft_atoi(text) == numbers[i]);
		free(text);
		i++;
	}
	list = ft_lstnew(ft_strdup("one"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("two")));
	assert(ft_lstsize(list) == 2);
	mapped = ft_lstmap(list, copy_content, free);
	assert(mapped && ft_lstsize(mapped) == 2);
	assert(!strcmp(mapped->content, "one"));
	assert(mapped->content != list->content);
	ft_lstclear(&mapped, free);
	ft_lstclear(&list, free);
	assert(!list && !mapped);
	puts("libft smoke checks passed");
	return (0);
}
