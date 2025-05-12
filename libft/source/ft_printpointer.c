/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:01:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/09 21:12:05 by groot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printpointer(unsigned long nbr)
{
	int	cpt;

	cpt = 0;
	if (nbr == 0)
		return (ft_printstr("(nil)"));
	cpt = 0;
	cpt += write(1, "0x", 2);
	cpt += ft_printfnumb_base_min(nbr);
	return (cpt);
}
