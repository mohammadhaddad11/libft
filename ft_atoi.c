/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:14:39 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/08 19:47:01 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int             ft_atoi(const char *nptr)
{
	int i;
	int neg;
	int result;

	result=0;
	i=0;
	neg=0;
	while((nptr[i] ==' ') ||(nptr[i]>8 && nptr[i] <14))
	{
		i++;
	}
	if(nptr[i] == '-')
	{
		neg=1;
		i++;
	}
	else if(nptr[i] == '+') {i++;}
	while(nptr[i] >='0' && nptr[i] <='9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	
	if(neg==1)
	{
		result= -result;
	}
	return(result);
}
