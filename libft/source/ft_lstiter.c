/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle_saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:52:05 by root              #+#    #+#             */
/*   Updated: 2024/11/13 12:48:02 by tle_saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// aplique la fonction a chaque element
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
