/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:43:02 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/23 17:45:24 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

char	**ft_flood_path(char **map, int ystart, int xstart, t_all *all)
{
	if (map[ystart][xstart] == '1')
		return (0);
	map[ystart][xstart] = '1';
	all->line = ft_tablen(map);
	all->column = ft_strlen(map[0]);
	if (ystart + 1 < all->line && map[ystart + 1][xstart] != '1')
		ft_flood_path(map, ystart + 1, xstart, all);
	if (ystart - 1 > 0 && map[ystart - 1][xstart] != '1')
		ft_flood_path(map, ystart - 1, xstart, all);
	if (xstart + 1 < all->column - 1 && map[ystart][xstart + 1] != '1')
		ft_flood_path(map, ystart, xstart + 1, all);
	if (xstart - 1 > 0 && map[ystart][xstart - 1] != '1')
		ft_flood_path(map, ystart, xstart - 1, all);
	return (map);
}

int	ft_tablen(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i - 1);
}

void	ft_init_var(t_all *game)
{
	game->mvleft = 0;
	game->mvright = 0;
	game->is_jumpimg = 0;
	game->nb_move = 0;
	game->mvleft = 0;
	game->mvright = 0;
	game->enemyvelocity = -2;
	game->xenemy = (game->column - 2) * 64;
	game->yenemy = (game->line - 1) * 64;
	game->destroyenemy = 0;
	game->hp = 5;
	game->counttimer = 0;
}

void	ft_velocity_apply(t_all *all)
{
	if (all->xvelocity < 0)
		all->xvelocity += 1;
	if (all->xvelocity > 0)
		all->xvelocity -= 1;
	if (all->yvelocity > 30)
		all->yvelocity = 30;
	if (all->yvelocity < -32)
		all->yvelocity = -32;
	if (all->xvelocity > 20)
		all->xvelocity = 20;
	if (all->xvelocity < -30)
		all->xvelocity = -30;
	if (ft_colision_down(all) == 0)
		all->yvelocity += 5;
	if (all->mvright == 1 && ft_colision_right(all) == 0)
		all->xvelocity += SPEED;
	if (all->mvleft == 1 && ft_colision_left(all) == 0)
		all->xvelocity -= SPEED;
	ft_count_move(all);
	all->xstart += all->xvelocity;
	all->ystart += all->yvelocity;
}

void	ft_free_map(t_all *all)
{
	int	i;

	i = 0;
	while (i <= all->line)
	{
		free(all->map[i]);
	}
	free(all->map);
}
