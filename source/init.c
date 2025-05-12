/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:19 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/23 18:13:56 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

char	**ft_init_tab(int fd)
{
	int		a;
	char	buffer[BUFFER_SIZE + 1];
	char	**tab;
	char	*line;

	line = NULL;
	tab = NULL;
	a = 0;
	while (1)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a < 1)
			break ;
		buffer[a] = '\0';
		if (line == NULL)
			line = ft_strdup(buffer);
		else
			line = ft_strjoinfree(&line, buffer);
	}
	tab = ft_split(line, '\n');
	free(line);
	return (tab);
}

int	ft_init_map(t_all *map, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error from file reading\n", 2), 1);
	map->map = NULL;
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	map->column = 0;
	map->line = 0;
	map->map = ft_init_tab(fd);
	map->isfree = 0;
	map->nbx64_move = NULL;
	map->lf = NULL;
	close(fd);
	return (0);
}

int	ft_total_check(int ac, t_all *game, char **av, char **map)
{
	if (ac != 2)
		return (ft_putstr_fd("Error\nWrong Arguments\n", 2), 1);
	if (ft_init_map(game, av[1]) != 0)
		return (ft_putstr_fd("Error\nProblem from Map init\n", 2), 1);
	if (ft_give_all_nbpoint(game) != 0 || ft_check_square(game) != 0)
		return (ft_putstr_fd("Error from map design\n", 2), 1);
	if (game->player != 1)
		return (ft_putstr_fd("Error\nProblem from Start POS\n", 2), 1);
	if (game->exit != 1)
		return (ft_putstr_fd("Error\nProblem from Exit POS\n", 2), 1);
	if (game->collectible == 0)
		return (ft_putstr_fd("Error\nNo Collectible\n", 2), 1);
	ft_give_start_pos(game);
	map = ft_copy_map(map, av[1]);
	if (ft_check_after_flood(ft_flood_path(map, game->ystart, game->xstart,
				game)) != 0)
		return (ft_putstr_fd("Error\nfrom Path\n", 2), 1);
	game->xvelocity = 0;
	game->yvelocity = 0;
	game->cheat = 0;
	ft_free_tab(map);
	return (ft_printf("Everything is Good, Launch the Game ...\n", 0), 0);
}

int	ft_give_all_nbpoint(t_all *map)
{
	int	i;
	int	j;

	ft_get_enemy_pos(map);
	i = 0;
	map->line = ft_tablen(map->map);
	map->column = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) != map->column)
			return (ft_putstr_fd("Line is not the same size\n", 2), 1);
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				map->player += 1;
			else if (map->map[i][j] == 'E')
				map->exit += 1;
			else if (map->map[i][j] == 'C')
				map->collectible += 1;
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_give_start_pos(t_all *game)
{
	game->ystart = 0;
	while (game->map[game->ystart])
	{
		game->xstart = 0;
		while (game->map[game->ystart][game->xstart])
		{
			if (game->map[game->ystart][game->xstart] == 'P')
				return (0);
			game->xstart++;
		}
		game->ystart++;
	}
	return (ft_putstr_fd("Starting POS Missing\n", 2), 1);
}
