/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:49:30 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/23 18:04:12 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

void	ft_double_jump(int keycode, t_all *all)
{
	if (keycode == LEFT && ft_colision_left(all) == 1 && all->is_jumpimg != 0)
	{
		all->xvelocity += 50;
		all->is_jumpimg = 1;
		all->yvelocity = -40;
	}
	if (keycode == RIGHT && ft_colision_right(all) == 1 && all->is_jumpimg != 0)
	{
		all->xvelocity -= 50;
		all->is_jumpimg = 1;
		all->yvelocity = -40;
	}
}

int	ft_handle_key_press(int keycode, t_all *all)
{
	ft_double_jump(keycode, all);
	if (keycode == RIGHT)
	{
		all->mvright = 1;
		all->mvleft = 0;
	}
	if (keycode == LEFT)
	{
		all->mvleft = 1;
		all->mvright = 0;
	}
	if (keycode == 53 || keycode == 65307)
	{
		ft_close_game(all);
		exit(0);
	}
	if (keycode == UP && ft_colision_up(all) == 0
		&& (all->is_jumpimg < 2 || all->cheat == 1))
	{
		all->yvelocity = -40;
		all->is_jumpimg += 1;
	}
	if (keycode == 32)
		all->cheat = 1;
	return (0);
}

int	ft_handle_key_release(int keycode, t_all *all)
{
	if (keycode == RIGHT)
	{
		all->mvright = 0;
	}
	if (keycode == LEFT)
	{
		all->mvleft = 0;
	}
	if (keycode == 32 && all->cheat == 1)
		all->cheat = 0;
	return (0);
}
