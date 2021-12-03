/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:04:48 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/02 17:07:01 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	help_draw(t_game_info *g_i, int i, int j)
{
	if (g_i->map[i][j] == '0')
		mlx_put_image_to_window(g_i->mlx, g_i->m_w, g_i->empty_space,
			(j * 32), (i * 32));
	if (g_i->map[i][j] == '1')
		mlx_put_image_to_window(g_i->mlx, g_i->m_w, g_i->wall,
			(j * 32), (i * 32));
	if (g_i->map[i][j] == 'C')
	{
		mlx_put_image_to_window(g_i->mlx, g_i->m_w, g_i->empty_space,
			(j * 32), (i * 32));
		mlx_put_image_to_window(g_i->mlx, g_i->m_w,
			g_i->collectible_pic, (j * 32), (i * 32));
	}
	if (g_i->map[i][j] == 'E')
	{
		mlx_put_image_to_window(g_i->mlx, g_i->m_w, g_i->empty_space,
			(j * 32), (i * 32));
		mlx_put_image_to_window(g_i->mlx, g_i->m_w, g_i->exit_pic,
			(j * 32), (i * 32));
		if (g_i->map[i][j] == g_i->map[g_i->p_y][g_i->p_x])
			mlx_put_image_to_window(g_i->mlx, g_i->m_w, g_i->player_d,
				(j * 32), (i * 32));
	}
}

void	draw_map(t_game_info *g_i)
{
	int	i;
	int	j;

	i = 0;
	while (g_i->map[i])
	{
		j = 0;
		while (g_i->map[i][j])
		{
			help_draw(g_i, i, j);
			if (g_i->map[i][j] == 'P')
			{
				mlx_put_image_to_window(g_i->mlx, g_i->m_w, g_i->empty_space,
					(j * 32), (i * 32));
				mlx_put_image_to_window(g_i->mlx, g_i->m_w, g_i->player_d,
					(j * 32), (i * 32));
			}
			j++;
		}
		i++;
	}
}
