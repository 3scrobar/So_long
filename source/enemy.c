/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:45:16 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/23 17:37:05 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

void	ft_enemy_patrol(t_all *all)
{
	if (all->enemyvelocity < 0 && all->map[(all->yenemy - 32)
			/ 64][((all->xenemy) / 64)] == '1')
		all->enemyvelocity = 4;
	if (all->enemyvelocity > 0 && all->map[(all->yenemy - 32)
			/ 64][((all->xenemy + 65) / 64)] == '1')
		all->enemyvelocity = -4;
	all->xenemy += all->enemyvelocity;
}

void	ft_enemy(t_all *all)
{
	if (all->destroyenemy == 0)
	{
		ft_enemy_patrol(all);
		ft_col_enemy(all);
		ft_manage_enemy(all);
	}
}

void	ft_manage_enemy(t_all *all)
{
	if (all->xstart + 64 >= all->xenemy
		&& all->xstart <= all->xenemy + 64
		&& all->ystart + 64 >= all->yenemy + 64)
	{
		all->hp -= 1;
		ft_give_start_pos(all);
		all->xstart *= 64;
		all->ystart *= 64;
	}
}

void	ft_col_enemy(t_all *all)
{
	if ((all->xstart + 32) >= all->xenemy
		&& (all->xstart + 32) <= all->xenemy + 64
		&& all->ystart + 64 >= all->yenemy
		&& all->ystart + 64 <= all->yenemy + 32)
	{
		all->destroyenemy = 1;
		mlx_destroy_image(all->mlx, all->imgenemyleft);
		mlx_destroy_image(all->mlx, all->imgenemyright);
		all->xenemy = 0;
		all->yenemy = 0;
		ft_putstr_fd("Enemy Destroyed\n", 1);
	}
}

void	ft_get_enemy_pos(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'E')
			{
				all->xenemy = j * 64;
				all->yenemy = i * 64;
			}
			j++;
		}
		i++;
	}
}
