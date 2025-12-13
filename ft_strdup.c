/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:29:32 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/08 20:42:09 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char *strdup(const char *s)
{
	size_t slen = ft_strlen(s);
	size_t i;
	char *p;

	i=0;
	p = malloc(slen+1);
	if(!p)
	{
		return(NULL);
	}
	while(s[i])
	{
		p[i]=s[i];
		i++;
	}
	p[i]='\0';
	return(p);
}

