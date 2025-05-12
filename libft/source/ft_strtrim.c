/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:18:59 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/12 15:56:25 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//remplace les charactere set trouver au debut et a la fin
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	while (*s1 && ft_strchr((char *)set, *s1) != NULL)
		s1++;
	i = ft_strlen((char *)s1) - 1;
	while (i > 0 && ft_strrchr(set, s1[i]) != NULL)
		i--;
	return (ft_substr(s1, 0, i + 1));
}
