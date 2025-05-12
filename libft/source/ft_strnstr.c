/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:15 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/08 14:58:09 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//chercher little dans big sur len longueur
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (big[i] && i + little_len <= len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j])
		{
			if (j == little_len - 1)
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
