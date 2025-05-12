/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:06:34 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/04 15:38:36 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_unsnbr(unsigned int n)
{
	unsigned int	cpt;

	cpt = 0;
	if (n >= 10)
	{
		cpt += ft_printf_unsnbr(n / 10);
	}
	n = (n % 10) + 48;
	cpt += write(1, &n, 1);
	return (cpt);
}
