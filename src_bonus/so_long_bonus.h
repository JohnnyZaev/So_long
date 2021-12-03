/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:48:32 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/03 15:06:48 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define TRUE 1
# define FLOOR_XPM "/Users/gvarys/Desktop/So_long/img/floor.xpm"
# define WALL_XPM "/Users/gvarys/Desktop/So_long/img/wall.xpm"
# define EXIT_XPM "/Users/gvarys/Desktop/So_long/img/exit.xpm"
# define DIA_XPM "/Users/gvarys/Desktop/So_long/img/Diamond_real_32x32.xpm"
# define PLAYER_XPM "/Users/gvarys/Desktop/So_long/img/player-d.xpm"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>
# include "../libs/minilibx_opengl_20191021/mlx.h"
# include "../libs/Libft/libft.h"

typedef struct s_map_info
{
	int	rows;
	int	columns;
	int	empty_space;
	int	collectible;
	int	map_exit;
	int	player_start;
	int	walls;
}	t_map_info;

typedef struct s_game_info
{
	void	*mlx;
	void	*m_w;
	char	**map;
	void	*wall;
	void	*empty_space;
	void	*exit_pic;
	void	*collectible_pic;
	void	*player_d;
	void	*trap1;
	void	*trap2;
	void	*trap3;
	int		rows;
	int		columns;
	int		collectible;
	int		movements;
	int		collected;
	int		exit;
	int		trap;
	int		img_h;
	int		img_w;
	int		player_position;
	int		p_x;
	int		p_y;
}	t_game_info;

int		map_is_valid(t_game_info *game_info, char *path);
int		check_valid(t_map_info	*map_info, t_game_info *game_info);
void	start_game(t_game_info *game_info);
int		destroy(t_game_info *game_info);
int		key_handler(int	keycode, t_game_info *game_info);
void	draw_map(t_game_info *game_info);
void	move(int keycode, t_game_info *game_info);
void	move_up(t_game_info *game_info);
void	move_right(t_game_info *game_info);
void	move_down(t_game_info *game_info);
void	move_left(t_game_info *game_info);
void	free_map(t_game_info *game_info);
void	move_count(t_game_info *g_i);
void	animation(t_game_info *g_i);

#endif