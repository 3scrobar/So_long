/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:42:51 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/23 18:12:58 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

int	ft_check_after_flood(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1')
				return (ft_putstr_fd("Error\nPath is invalid\n", 2), 1);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}

int	ft_check_border(t_all *map)
{
	int	i;

	i = 0;
	while (i < map->column)
	{
		if (map->map[0][i] != '1' || map->map[map->line][i] != '1')
			return (ft_putstr_fd("Error\nfrom map border\n", 2), 1);
		i++;
	}
	i = 0;
	while (i <= map->line)
	{
		if (map->map[i][0] != '1' || map->map[i][map->column - 1] != '1')
			return (ft_putstr_fd("Error\nfrom map border\n", 2), 1);
		i++;
	}
	return (0);
}

int	ft_check_square(t_all *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (j != map->column)
			return (ft_putstr_fd("Error\nLine as not the same size\n", 2), 1);
		i++;
	}
	return (0);
}

void	ft_security_check(t_all *all)
{
	if (all->map[((all->ystart) / all->tile_size)][((all->xstart + 32)
			/ all->tile_size)] == 'C')
	{
		all->map[((all->ystart) / all->tile_size)][((all->xstart + 32)
				/ all->tile_size)] = '0';
		all->collectible -= 1;
	}
	if (all->map[((all->ystart) / all->tile_size)][((all->xstart + 32)
			/ all->tile_size)] == 'E' && all->collectible == 0)
	{
		ft_printf("You Win in %d move\n", all->nb_move / 64);
		ft_close_game(all);
		exit(0);
	}
}

int	ft_close_game(t_all *all)
{
	mlx_destroy_window(all->mlx, all->win);
	ft_free_image(all);
	mlx_destroy_display(all->mlx);
	free(all->mlx);
	ft_free_tab(all->map);
	free(all->lf);
	free(all->nbx64_move);
	exit(0);
}
