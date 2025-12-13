/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:12:04 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/03 16:15:43 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void *ft_memset(void *s, int c, size_t n)
{
	unsigned char *p =  (unsigned char *)s;

	while (n >0)
	{
		*p =(unsigned char)c;
		p++;
		n--;
	}
	return(s);
}
