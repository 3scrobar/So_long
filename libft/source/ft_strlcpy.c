/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:25:00 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/08 14:57:04 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//copier 2 chaine de charactere
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	i;

	i = 0;
	s = size - 1;
	if (size != 0)
	{
		while (i < s && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
