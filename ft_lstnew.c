/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:36:09 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/13 15:14:31 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
t_list *ft_lstnew(void *content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content=content;
	new->next = NULL;
	return(new);
}
