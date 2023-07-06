/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:18 by nihamdan          #+#    #+#             */
/*   Updated: 2023/07/05 19:53:41 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_fill(t_all *so_long, int j, int i, int *exit)
{
	if (so_long->cpy_map[j][i] == 'P' || so_long->cpy_map[j][i] == 'V')
	{
		if (so_long->cpy_map[j][i] == 'P')
			so_long->cpy_map[j][i] = 'V';
		if (so_long->cpy_map[j][i + 1] != '1')
			map_fill2(so_long, j, i + 1, exit);
		if (so_long->cpy_map[j][i - 1] != '1')
			map_fill2(so_long, j, i - 1, exit);
		if (so_long->cpy_map[j + 1][i] != '1')
			map_fill2(so_long, j + 1, i, exit);
		if (so_long->cpy_map[j - 1][i] != '1')
			map_fill2(so_long, j - 1, i, exit);
	}
	return ;
}

void	map_fill2(t_all *so_long, int j, int i, int *exit)
{
	if (so_long->cpy_map[j][i] == 'V')
		return ;
	if (so_long->cpy_map[j][i] == 'C')
		so_long->collectibles--;
	if (so_long->cpy_map[j][i] == 'E')
		*exit = 1;
	so_long->cpy_map[j][i] = 'V';
	so_long->flag_map = 0;
	return ;
}

void	init_so_long(t_all *so_long, char *argv)
{
	so_long->map_size = 0;
	so_long->collectibles = 0;
	so_long->exit_count = 0;
	so_long->position_count = 0;
	so_long->collectible_count = 0;
	so_long->flag_map = 0;
	so_long->step = 0;
	so_long->exitoffpath = "./xpm/exitoff.xpm";
	so_long->exitonpath = "./xpm/exiton.xpm";
	so_long->groundpath = "./xpm/ground.xpm";
	so_long->charpath = "./xpm/char.xpm";
	so_long->collectpath = "./xpm/collect.xpm";
	so_long->wallpath = "./xpm/wall.xpm";
	so_long->mlx_ptr = NULL;
	so_long->wdw_ptr = NULL;
	init_map(so_long, argv);
	cpy_map(so_long, argv);
	return ;
}
