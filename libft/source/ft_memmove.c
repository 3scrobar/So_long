/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:40:37 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/08 14:54:02 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//permet de deplacer la memoire sans risque de perte
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	c;

	if (dest == NULL && src == NULL)
		return (dest);
	c = 0;
	if (dest < src)
	{
		while (c < n)
		{
			*(unsigned char *)(dest + c) = *(unsigned char *)(src + c);
			c++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
		}
	}
	return (dest);
}
