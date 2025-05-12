/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnum_base_maj.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:06:05 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/09 21:12:13 by groot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_printfnumb_base_maj(unsigned int nbr)
{
	unsigned int	cpt;
	char			*str;

	cpt = 0;
	str = "0123456789ABCDEF";
	if (nbr >= 16)
		cpt += ft_printfnumb_base_maj(nbr / 16);
	cpt += write(1, &str[nbr % 16], 1);
	return (cpt);
}
