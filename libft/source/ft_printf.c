/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:37:33 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/09 21:11:59 by groot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_printf(const char *str, ...)
{
	unsigned int	cpt;
	va_list			args;

	va_start(args, str);
	cpt = 0;
	while (*str)
	{
		if (*str != '%')
		{
			cpt += write(1, str, 1);
			str++;
		}
		else
		{
			str++;
			cpt += ft_check(args, *str);
			str++;
		}
	}
	va_end(args);
	return (cpt);
}
