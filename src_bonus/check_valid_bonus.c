/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:24:17 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/03 12:41:21 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_to_check(t_map_info *m, t_game_info *g, int i, int j)
{
	if (g->map[i][j] == '0')
		m->empty_space++;
	else if (g->map[i][j] == '1')
		m->walls++;
	else if (g->map[i][j] == 'C')
		m->collectible++;
	else if (g->map[i][j] == 'E')
		m->map_exit++;
	else if (g->map[i][j] == 'P')
	{
		m->player_start++;
		g->p_x = j;
		g->p_y = i;
	}
	else if (g->map[i][j] == 'T')
		g->trap = 1;
	else
		return (1);
	return (0);
}

static int	check_char(t_map_info *map_info, t_game_info *game_info)
{
	int	i;
	int	j;

	i = 0;
	map_info->rows = ft_strlen(game_info->map[0]);
	while (game_info->map[i])
	{
		j = 0;
		while (game_info->map[i][j])
		{
			if (check_to_check(map_info, game_info, i, j) == 1)
				return (1);
			j++;
		}
		if (map_info->rows != j)
			return (1);
		i++;
	}
	map_info->columns = i;
	return (0);
}

static int	check_walls(t_map_info	*map_info, t_game_info *game_info)
{
	int	i;
	int	j;

	i = 0;
	while (game_info->map[i])
	{
		j = 0;
		while (game_info->map[i][j])
		{
			if (game_info->map[0][j] != '1' || game_info->map[i][0] != '1'
				|| game_info->map[map_info->columns - 1][j] != '1'
				|| game_info->map[i][map_info->rows - 1] != '1')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	minimum_info(t_map_info *map_info)
{
	if (map_info->player_start < 1 || map_info->collectible < 1
		|| map_info->map_exit < 1)
		return (1);
	return (0);
}

int	check_valid(t_map_info	*map_info, t_game_info *game_info)
{
	if (check_char(map_info, game_info))
		return (1);
	if (check_walls(map_info, game_info) || minimum_info(map_info))
		return (1);
	return (0);
}
