/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:35:59 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/23 17:18:54 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fps(t_all *all)
{
	if (all->counttimer >= 1500)
	{
		ft_game_loop(all);
		all->counttimer = 0;
	}
	else if (all->counttimer < 1500)
	{
		all->counttimer++;
	}
	return (0);
}

void	ft_free_image(t_all *all)
{
	if (all->imgcollectible != NULL)
		mlx_destroy_image(all->mlx, all->imgcollectible);
	if (all->imgenemyleft != NULL && all->destroyenemy == 0)
		mlx_destroy_image(all->mlx, all->imgenemyleft);
	if (all->imgenemyright != NULL && all->destroyenemy == 0)
		mlx_destroy_image(all->mlx, all->imgenemyright);
	if (all->imgexit != NULL)
		mlx_destroy_image(all->mlx, all->imgexit);
	if (all->imgfont != NULL)
		mlx_destroy_image(all->mlx, all->imgfont);
	if (all->imgplayercenter != NULL)
		mlx_destroy_image(all->mlx, all->imgplayercenter);
	if (all->imgplayerleft != NULL)
		mlx_destroy_image(all->mlx, all->imgplayerleft);
	if (all->imgplayerright != NULL)
		mlx_destroy_image(all->mlx, all->imgplayerright);
	if (all->imgwall != NULL)
		mlx_destroy_image(all->mlx, all->imgwall);
	if (all->exitcover != NULL)
		mlx_destroy_image(all->mlx, all->exitcover);
}

char	**ft_copy_map(char **map, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error from file reading\n", 2), NULL);
	map = NULL;
	map = ft_init_tab(fd);
	close(fd);
	return (map);
}

void	ft_free_tab(char **tab)
{
	int	i;
	int	len;

	i = 0;
	len = ft_tablen(tab);
	while (i <= len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_count_move(t_all *all)
{
	if (all->xvelocity < 0)
		all->nb_move -= all->xvelocity;
	if (all->xvelocity > 0)
		all->nb_move += all->xvelocity;
	if (all->yvelocity < 0)
		all->nb_move -= all->yvelocity;
	if (all->yvelocity > 0)
		all->nb_move += all->yvelocity;
}
