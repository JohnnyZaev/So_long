/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:47:54 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/02 14:54:07 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_info	g_i;

	if (argc == 2)
	{
		if (map_is_valid(&g_i, argv[1]))
		{
			start_game(&g_i);
			return (0);
		}
		else
		{
			free_map(&g_i);
			printf("Invalid map");
			return (0);
		}
	}
	else
	{
		printf("Invalid number of arguments: %i\nShould be 2", argc);
		exit(0);
	}
	return (0);
}
