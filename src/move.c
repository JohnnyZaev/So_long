/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:39:32 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/02 16:48:08 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	help_move_lr(t_game_info *g_i, int i)
{
	if (g_i->map[g_i->p_y][g_i->p_x + i] == '0')
	{
		if (g_i->map[g_i->p_y][g_i->p_x] == 'P')
			g_i->map[g_i->p_y][g_i->p_x] = '0';
		else
			g_i->map[g_i->p_y][g_i->p_x] = 'E';
		g_i->map[g_i->p_y][g_i->p_x + i] = 'P';
		g_i->movements++;
	}
	if (g_i->map[g_i->p_y][g_i->p_x + i] == 'C')
	{
		g_i->map[g_i->p_y][g_i->p_x] = '0';
		g_i->map[g_i->p_y][g_i->p_x + i] = 'P';
		g_i->collectible--;
		g_i->movements++;
	}
}

void	move_left(t_game_info *g_i)
{
	if (g_i->map[g_i->p_y][g_i->p_x - 1] == '1')
		return ;
	help_move_lr(g_i, -1);
	if (g_i->map[g_i->p_y][g_i->p_x - 1] == 'E')
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
	g_i->p_x--;
	printf("Movemens: %i\n", g_i->movements);
	draw_map(g_i);
}

void	move_right(t_game_info *g_i)
{
	if (g_i->map[g_i->p_y][g_i->p_x + 1] == '1')
		return ;
	help_move_lr(g_i, 1);
	if (g_i->map[g_i->p_y][g_i->p_x + 1] == 'E')
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
	g_i->p_x++;
	printf("Movemens: %i\n", g_i->movements);
	draw_map(g_i);
}
