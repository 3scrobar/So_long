/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2025/03/31 16:33:32 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_all	game;
	char	**mapcpy;

	mapcpy = NULL;
	game.timerprint = 0;
	game.mlx = mlx_init();
	if (ft_total_check(ac, &game, av, mapcpy) != 0 || game.mlx == NULL)
		return (free(game.mlx), 1);
	if (ft_init_img(&game) != 0)
		return (free(game.mlx), ft_putstr_fd("Error\n", 2), 1);
	game.win = mlx_new_window(game.mlx, game.column * 64,
			(game.line + 1) * 64, "so_long");
	game.xstart = game.xstart * game.tile_size;
	game.ystart = game.ystart * game.tile_size;
	ft_init_var(&game);
	mlx_hook(game.win, 17, 1L << 17, ft_close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_handle_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_handle_key_release, &game);
	mlx_loop_hook(game.mlx, ft_fps, &game);
	mlx_loop(game.mlx);
	return (0);
}

int	ft_game_loop(t_all *game)
{
	if (game->nbx64_move != NULL)
		free(game->nbx64_move);
	if (game->lf != NULL)
		free(game->lf);
	if (game->nb_move >= 1)
		game->nbx64_move = ft_itoa(game->nb_move / 64);
	game->lf = ft_itoa(game->hp);
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	ft_print_nummv(game);
	ft_if_gameloop(game);
	ft_velocity_apply(game);
	ft_collision_check(game);
	ft_security_check(game);
	mlx_string_put(game->mlx, game->win, 900, 20, 0xFF0000, "Nbr PDV : ");
	mlx_string_put(game->mlx, game->win, 980, 20, 0xFF0000, game->lf);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFF0000, "Nbr mouvements");
	if (game->nbx64_move != NULL)
		mlx_string_put(game->mlx, game->win, 100, 20, 0xFF0000,
			game->nbx64_move);
	ft_enemy(game);
	return (0);
}

void	ft_if_gameloop(t_all *game)
{
	if (game->xvelocity < 0)
		mlx_put_image_to_window(game->mlx, game->win, game->imgplayerleft,
			game->xstart, game->ystart);
	if (game->xvelocity > 0)
		mlx_put_image_to_window(game->mlx, game->win, game->imgplayerright,
			game->xstart, game->ystart);
	if (game->xvelocity == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->imgplayercenter,
			game->xstart, game->ystart);
	if (game->enemyvelocity < 0 && game->destroyenemy == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->imgenemyleft,
			game->xenemy, game->yenemy);
	if (game->enemyvelocity > 0 && game->destroyenemy == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->imgenemyright,
			game->xenemy, game->yenemy);
	if (game->hp == 0)
		ft_close_game(game);
}

void	ft_print_nummv(t_all *all)
{
	if (all->timerprint >= 50)
	{
		if (all->nbx64_move != NULL)
		{
			ft_printf("Nombre de Mouvement :  ");
			ft_putendl_fd(all->nbx64_move, 1);
		}
		all->timerprint = 0;
	}
	else
		all->timerprint++;
}
