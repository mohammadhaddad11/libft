/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:04:21 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/08 09:53:16 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void *ft_memmove(void *dest, const void *src, size_t n)
{
        const unsigned char *ps;
        unsigned char *pd;

        if (!dest && !src)
                return (NULL);

        ps = (unsigned char *)src;
        pd = (unsigned char *)dest;

        if (pd > ps) 
	{
		while (n > 0)
		{
			n--; 
			pd[n] = ps[n];
		}
	}
	else
	{
		while (n > 0)
		{
			*pd = *ps;
			pd++;
			ps++;
			n--;
		}
	}
	return (dest);
}
