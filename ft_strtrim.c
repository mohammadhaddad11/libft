/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:03:45 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/08 21:51:14 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	start;
	size_t	end;
	size_t	s1_len;
	size_t	len;

	s1_len = ft_strlen(s1);
	start = 0;
	while(s1[start] && ft_strchr(set,s1[start]))
	{
		start++;
	}
	if (start == s1_len)
	{
		return (ft_strdup(""));
	}
	end = s1_len - 1;
	while(end > start && ft_strchr(set,s1[end]))
        {
                end--;
        }
	len = end - start + 1;

	p = malloc(len);
	ft_memcpy(p, &s1[start], len);
	p[len] = '\0';
	
	return(p);
}
