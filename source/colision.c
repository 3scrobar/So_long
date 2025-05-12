/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:47:17 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/15 17:13:15 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

int	ft_collision_check(t_all *all)
{
	if (ft_colision_right(all) == 1)
	{
		all->xvelocity = 0;
	}
	if (ft_colision_left(all) == 1)
	{
		all->xvelocity = 0;
	}
	if (ft_colision_up(all) == 1)
	{
		all->yvelocity = 0;
	}
	if (ft_colision_down(all) == 1)
	{
		all->yvelocity = 0;
		all->ystart = (all->ystart / all->tile_size) * all->tile_size;
		all->is_jumpimg = 0;
	}
	return (0);
}

int	ft_colision_right(t_all *all)
{
	int	right;

	right = (all->xstart + 58) / all->tile_size;
	if (all->map[((all->ystart + 32) / all->tile_size)][right] == '1')
		return (1);
	return (0);
}

int	ft_colision_left(t_all *all)
{
	int	left;

	left = ((all->xstart + 10) / all->tile_size);
	if (all->map[(all->ystart + 48) / all->tile_size][left] == '1')
		return (1);
	return (0);
}

int	ft_colision_up(t_all *all)
{
	int	top;

	top = ((all->ystart + 31) / all->tile_size);
	if (all->map[top][(all->xstart + 32) / all->tile_size] == '1' || top == 0)
		return (1);
	return (0);
}

int	ft_colision_down(t_all *all)
{
	int	bottom;

	bottom = ((all->ystart + 65) / 64);
	if (all->map[bottom][(all->xstart + 32) / all->tile_size] == '1')
		return (1);
	return (0);
}
