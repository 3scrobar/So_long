/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnumb_base_min.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:31:57 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/09 21:12:16 by groot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printfnumb_base_min(unsigned long nbr)
{
	unsigned int	cpt;
	char			*str;

	cpt = 0;
	str = "0123456789abcdef";
	if (nbr >= 16)
		cpt += ft_printfnumb_base_min(nbr / 16);
	cpt += write(1, &str[nbr % 16], 1);
	return (cpt);
}
