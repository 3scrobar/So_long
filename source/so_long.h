/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:52 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/23 17:55:21 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/source/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define RIGHT 100
# define LEFT 97
# define UP 119
# define DOWN 115
# define SPEED 2

typedef struct s_all
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**mapcpy;
	int		line;
	int		column;
	size_t	player;
	size_t	exit;
	size_t	collectible;
	int		xstart;
	int		ystart;
	int		tile_size;
	void	*imgfont;
	void	*imgwall;
	void	*imgexit;
	void	*imgcollectible;
	void	*imgplayerright;
	void	*imgplayerleft;
	void	*imgplayercenter;
	void	*imgenemyright;
	void	*imgenemyleft;
	void	*exitcover;
	int		xvelocity;
	int		yvelocity;
	int		gravity;
	int		mvleft;
	int		mvright;
	int		is_jumpimg;
	int		nb_move;
	int		enemyvelocity;
	int		xenemy;
	int		yenemy;
	int		destroyenemy;
	int		hp;
	int		counttimer;
	char	*nbx64_move;
	char	*lf;
	int		isfree;
	int		cheat;
	int		timerprint;
}				t_all;

int		ft_tablen(char	**tab);
int		ft_give_all_nbpoint(t_all *map);
int		ft_check_square(t_all *map);
int		ft_give_start_pos(t_all *game);
char	**ft_flood_path(char **map, int y, int x, t_all *all);
int		ft_check_after_flood(char **map);
char	**ft_init_tab(int fd);
int		ft_init_map(t_all *map, char *path);
int		ft_copy_struct(t_all *game, t_all *cpy);
int		ft_total_check(int ac, t_all *game, char **av, char **map);
int		ft_check_border(t_all *map);
int		ft_close(t_all *game, int nb);
int		ft_game_loop(t_all *game);
int		draw_map(t_all *all);
int		ft_init_img(t_all *game);
void	ft_print_tab(char **tab);
int		ft_malloc_map(t_all *game, t_all *cpy);
void	ft_velocity_apply(t_all *game);
int		ft_collision_check(t_all *game);
void	ft_security_check(t_all *game);
int		ft_col_check(t_all *game);
int		ft_colision_right(t_all *all);
int		ft_colision_left(t_all *all);
int		ft_colision_up(t_all *all);
int		ft_colision_down(t_all *all);
int		ft_handle_key_press(int keycode, t_all *all);
int		ft_handle_key_release(int keycode, t_all *all);
void	ft_manage_enemy(t_all *game);
void	ft_col_enemy(t_all *game);
void	ft_init_var(t_all *game);
void	ft_double_jump(int keycode, t_all *all);
void	ft_enemy_patrol(t_all *all);
void	ft_enemy(t_all *all);
void	ft_col_enemy(t_all *game);
void	ft_enemy_patrol(t_all *all);
void	ft_get_enemy_pos(t_all *game);
void	ft_if_draw(t_all *all, int y, int x);
void	ft_if_gameloop(t_all *game);
int		ft_fps(t_all *all);
void	ft_free_map(t_all *map);
void	ft_free_image(t_all *all);
char	**ft_copy_map(char **map, char *path);
void	ft_free_tab(char **tab);
void	ft_count_move(t_all *all);
int		ft_close_game(t_all *all);
void	ft_print_nummv(t_all *all);

#endif
