/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:50:04 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/02 16:57:00 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_ud(t_game_info *g_i, int i)
{
	if (g_i->map[g_i->p_y + i][g_i->p_x] == '0')
	{
		if (g_i->map[g_i->p_y][g_i->p_x] == 'P')
			g_i->map[g_i->p_y][g_i->p_x] = '0';
		else
			g_i->map[g_i->p_y][g_i->p_x] = 'E';
		g_i->map[g_i->p_y + i][g_i->p_x] = 'P';
		g_i->movements++;
	}
	if (g_i->map[g_i->p_y + i][g_i->p_x] == 'C')
	{
		g_i->map[g_i->p_y][g_i->p_x] = '0';
		g_i->map[g_i->p_y + i][g_i->p_x] = 'P';
		g_i->collectible--;
		g_i->movements++;
	}
}

void	move_down(t_game_info *g_i)
{
	if (g_i->map[g_i->p_y + 1][g_i->p_x] == '1')
		return ;
	move_ud(g_i, 1);
	if (g_i->map[g_i->p_y + 1][g_i->p_x] == 'E')
	{
		if (g_i->collectible == 0)
		{
			g_i->movements++;
			printf("Congratulations, you won in %i steps!\n", g_i->movements);
			destroy(g_i);
		}
		else
		{
			g_i->map[g_i->p_y][g_i->p_x] = '0';
			g_i->movements++;
		}
	}
	g_i->p_y++;
	printf("Movemens: %i\n", g_i->movements);
	draw_map(g_i);
}

void	move_up(t_game_info *g_i)
{
	if (g_i->map[g_i->p_y - 1][g_i->p_x] == '1')
		return ;
	move_ud(g_i, -1);
	if (g_i->map[g_i->p_y - 1][g_i->p_x] == 'E')
	{
		if (g_i->collectible == 0)
		{
			g_i->movements++;
			printf("Congratulations, you won in %i steps!\n", g_i->movements);
			destroy(g_i);
		}
		else
		{
			g_i->map[g_i->p_y][g_i->p_x] = '0';
			g_i->movements++;
		}
	}
	g_i->p_y--;
	printf("Movemens: %i\n", g_i->movements);
	draw_map(g_i);
}

void	move(int keycode, t_game_info *game_info)
{
	if (keycode == 0)
		move_left(game_info);
	if (keycode == 1)
		move_down(game_info);
	if (keycode == 2)
		move_right(game_info);
	if (keycode == 13)
		move_up(game_info);
}
