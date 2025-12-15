/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:01:59 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/15 19:15:14 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_free();
char	ft_word(char *s);
int	ft_len(char *s);
char	**ft_split(char const *s, char c)
{
	char **arr;

	arr=malloc();
	if(!arr)
	{
		return(NULL);
	}
}
