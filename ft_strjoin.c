/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:43:18 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/08 21:03:31 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char *ft_strjoin(char const *s1, char const *s2)
{
	char *p;
	size_t s1_len;
	size_t s2_len;

	if (!s1 || !s2)
        {
                return(NULL);
        }
	s1_len= ft_strlen(s1);
	s2_len= ft_strlen(s2);

	p = malloc(s1_len + s2_len + 1);
	if(!p)
	{
		return(NULL);
	}
	ft_memcpy(p,s1,s1_len+1);
	ft_strlcat(p, s2, s1_len + s2_len + 1);
	return(p);
}
