/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:14:45 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/02 14:44:06 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map_info(t_map_info *map_info)
{
	map_info->rows = 0;
	map_info->columns = 0;
	map_info->empty_space = 0;
	map_info->collectible = 0;
	map_info->map_exit = 0;
	map_info->player_start = 0;
	map_info->walls = 0;
}

static char	**get_map(char *path)
{
	int		fd;
	char	**map;
	char	*temp;
	char	*map_oneline;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_oneline = ft_strdup("");
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = map_oneline;
		map_oneline = ft_strjoin(temp, line);
		free(temp);
		free(line);
	}
	map = ft_split(map_oneline, '\n');
	free(map_oneline);
	close(fd);
	return (map);
}

static int	valid_extension(char *path)
{	
	const char	*ext;

	if (!path)
		return (1);
	ext = ft_strchr(path, '.');
	if (ft_strncmp(ext, ".ber", 5))
		return (1);
	return (0);
}

int	map_is_valid(t_game_info *g_i, char *path)
{
	t_map_info	map_info;

	g_i->map = get_map(path);
	if (!g_i->map)
		return (0);
	init_map_info(&map_info);
	if (check_valid(&map_info, g_i) || valid_extension(path))
		return (0);
	g_i->rows = map_info.rows;
	g_i->columns = map_info.columns;
	g_i->collectible = map_info.collectible;
	return (1);
}
