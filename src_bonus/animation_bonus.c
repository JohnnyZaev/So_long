/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:50:15 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/03 15:04:07 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	help_dt(t_game_info *g_i, int step, int j, int i)
{
	if (step == 3)
	{
		mlx_put_image_to_window(g_i->mlx, g_i->m_w,
			g_i->empty_space, j * 32, i * 32);
		mlx_put_image_to_window(g_i->mlx, g_i->m_w,
			g_i->trap2, j * 32, i * 32);
	}
	if (step == 2)
	{
		mlx_put_image_to_window(g_i->mlx, g_i->m_w,
			g_i->empty_space, j * 32, i * 32);
		mlx_put_image_to_window(g_i->mlx, g_i->m_w,
			g_i->trap1, j * 32, i * 32);
	}
	if (step == 1)
	{
		mlx_put_image_to_window(g_i->mlx, g_i->m_w,
			g_i->empty_space, j * 32, i * 32);
		mlx_put_image_to_window(g_i->mlx, g_i->m_w,
			g_i->trap3, j * 32, i * 32);
	}
}

static void	draw_traps(t_game_info *g_i, int step)
{
	int	i;
	int	j;

	i = 0;
	while (g_i->map[i])
	{
		j = 0;
		while (g_i->map[i][j])
		{
			if (g_i->map[i][j] == 'T')
				help_dt(g_i, step, j, i);
			j++;
		}
		i++;
	}
}

static int	trap_animation(t_game_info *g_i)
{
	static time_t	seconds;
	static int		steps = 0;
	time_t			temp;

	if (!seconds)
		time(&seconds);
	time(&temp);
	if (seconds == temp - 1)
	{	
		steps++;
		draw_traps(g_i, steps);
		seconds = 0;
		if (steps == 3)
			steps = 0;
	}
	return (0);
}

void	animation(t_game_info *g_i)
{
	if (g_i->trap > 0)
	{
		g_i->trap1 = mlx_xpm_file_to_image
			(g_i->mlx, "/Users/gvarys/Desktop/So_long/img/trap1.xpm",
				&g_i->img_h, &g_i->img_w);
		g_i->trap2 = mlx_xpm_file_to_image
			(g_i->mlx, "/Users/gvarys/Desktop/So_long/img/trap2.xpm",
				&g_i->img_h, &g_i->img_w);
		g_i->trap3 = mlx_xpm_file_to_image
			(g_i->mlx, "/Users/gvarys/Desktop/So_long/img/trap3.xpm",
				&g_i->img_h, &g_i->img_w);
		draw_traps(g_i, 1);
		mlx_loop_hook(g_i->mlx, &trap_animation, g_i);
	}
}
