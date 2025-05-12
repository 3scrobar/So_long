/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:45:36 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/15 17:15:57 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

int	draw_map(t_all *all)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			ft_if_draw(all, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_if_draw(t_all *all, int y, int x)
{
	if (all->map[y][x] == '0')
		mlx_put_image_to_window(all->mlx, all->win, all->imgfont,
			x * all->tile_size, y * all->tile_size);
	else if (all->map[y][x] == '1')
		mlx_put_image_to_window(all->mlx, all->win, all->imgwall,
			x * all->tile_size, y * all->tile_size);
	else if (all->map[y][x] == 'E' && all->collectible == 0)
		mlx_put_image_to_window(all->mlx, all->win, all->imgexit,
			x * all->tile_size, y * all->tile_size);
	else if (all->map[y][x] == 'E' && all->collectible != 0)
		mlx_put_image_to_window(all->mlx, all->win, all->exitcover,
			x * all->tile_size, y * all->tile_size);
	else if (all->map[y][x] == 'C')
		mlx_put_image_to_window(all->mlx, all->win, all->imgcollectible,
			x * all->tile_size, y * all->tile_size);
}

int	ft_init_img(t_all *all)
{
	all->imgfont = mlx_xpm_file_to_image(all->mlx, "img/font.xpm",
			&all->tile_size, &all->tile_size);
	all->imgwall = mlx_xpm_file_to_image(all->mlx, "img/wall.xpm",
			&all->tile_size, &all->tile_size);
	all->imgexit = mlx_xpm_file_to_image(all->mlx, "img/window.xpm",
			&all->tile_size, &all->tile_size);
	all->exitcover = mlx_xpm_file_to_image(all->mlx, "img/door_closedMid.xpm",
			&all->tile_size, &all->tile_size);
	all->imgcollectible = mlx_xpm_file_to_image(all->mlx, "img/coinGold.xpm",
			&all->tile_size, &all->tile_size);
	all->imgplayerright = mlx_xpm_file_to_image(all->mlx, "img/playerright.xpm",
			&all->tile_size, &all->tile_size);
	all->imgplayerleft = mlx_xpm_file_to_image(all->mlx, "img/playerleft.xpm",
			&all->tile_size, &all->tile_size);
	all->imgplayercenter = mlx_xpm_file_to_image(all->mlx,
			"img/playercenter.xpm", &all->tile_size, &all->tile_size);
	all->imgenemyright = mlx_xpm_file_to_image(all->mlx, "img/enemyright.xpm",
			&all->tile_size, &all->tile_size);
	all->imgenemyleft = mlx_xpm_file_to_image(all->mlx, "img/enemyleft.xpm",
			&all->tile_size, &all->tile_size);
	if (all->imgfont == NULL || all->imgwall == NULL || all->imgexit == NULL
		|| all->imgcollectible == NULL
		|| all->imgplayerright == NULL || all->imgplayerleft == NULL)
		return (ft_putstr_fd("Error load an img\n", 2), 1);
	return (0);
}
