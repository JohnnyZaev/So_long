/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:30:49 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/02 17:05:08 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game_info *g_i)
{
	ssize_t	i;

	if (!g_i->map)
		return ;
	i = 0;
	while (g_i->map[i])
	{
		free(g_i->map[i]);
		g_i->map[i] = NULL;
		i++;
	}
	free(g_i->map);
	g_i->map = NULL;
}

int	key_handler(int	keycode, t_game_info *game_info)
{
	if (keycode == 53)
		destroy(game_info);
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		move(keycode, game_info);
	return (0);
}

int	destroy(t_game_info *game_info)
{
	mlx_destroy_image(game_info->mlx, game_info->empty_space);
	mlx_destroy_image(game_info->mlx, game_info->wall);
	mlx_destroy_image(game_info->mlx, game_info->collectible_pic);
	mlx_destroy_image(game_info->mlx, game_info->exit_pic);
	mlx_destroy_image(game_info->mlx, game_info->player_d);
	mlx_destroy_window(game_info->mlx, game_info->m_w);
	free_map(game_info);
	exit(0);
	return (0);
}

void	start_game(t_game_info *g_i)
{
	g_i->mlx = mlx_init();
	g_i->movements = 0;
	g_i->collected = 0;
	g_i->exit = 0;
	g_i->img_h = 32;
	g_i->img_w = 32;
	g_i->m_w = mlx_new_window
		(g_i->mlx, g_i->rows * 32, g_i->columns * 32, "So_long");
	g_i->empty_space = mlx_xpm_file_to_image
		(g_i->mlx, FLOOR_XPM, &g_i->img_h, &g_i->img_w);
	g_i->wall = mlx_xpm_file_to_image
		(g_i->mlx, WALL_XPM, &g_i->img_h, &g_i->img_w);
	g_i->exit_pic = mlx_xpm_file_to_image
		(g_i->mlx, EXIT_XPM, &g_i->img_h, &g_i->img_w);
	g_i->collectible_pic = mlx_xpm_file_to_image
		(g_i->mlx, DIA_XPM, &g_i->img_h, &g_i->img_w);
	g_i->player_d = mlx_xpm_file_to_image
		(g_i->mlx, PLAYER_XPM, &g_i->img_h, &g_i->img_w);
	draw_map(g_i);
	mlx_hook(g_i->m_w, 2, 1L << 0, &key_handler, g_i);
	mlx_hook(g_i->m_w, 17, 0, &destroy, g_i);
	mlx_loop(g_i->mlx);
}
