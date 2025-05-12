/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle_saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:01:34 by tle_saut          #+#    #+#             */
/*   Updated: 2024/11/13 13:19:54 by tle_saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*result;
	t_list	*new_node;

	result = NULL;
	current = lst;
	if (!lst || !f)
		return (NULL);
	while (current != NULL)
	{
		new_node = ft_lstnew(f(current->content));
		if (new_node == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_node);
		current = current->next;
	}
	return (result);
}
