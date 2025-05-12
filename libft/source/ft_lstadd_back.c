/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle_saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:35:39 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/13 12:49:19 by tle_saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_one;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new_one = *lst;
	while (new_one->next != NULL)
		new_one = new_one->next;
	new_one->next = new;
}
