/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:42:29 by nihamdan          #+#    #+#             */
/*   Updated: 2023/07/05 19:45:38 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_char_position(t_all *so_long)
{
	int	x;
	int	y;

	y = -1;
	while (++y < so_long->map_size)
	{
		x = -1;
		while (++x < so_long->map_length)
		{
			if (so_long->map[y][x] == 'P')
			{
				so_long->char_x = x;
				so_long->char_y = y;
			}
		}
	}
}

void	move_char(t_all *so_long, int x, int y)
{
	if (so_long->map[y][x] == 'E')
	{
		ft_printf("Steps = %d\n", ++so_long->step);
		check_collect(so_long, x, y);
	}
	else if (so_long->map[y][x] != '1')
	{
		ft_printf("Steps = %d\n", ++so_long->step);
		if (so_long->map[y][x] == 'C')
			so_long->collect_game--;
		so_long->map[y][x] = 'P';
		if (so_long->map[so_long->char_y][so_long->char_x] == 'T')
			so_long->map[so_long->char_y][so_long->char_x] = 'E';
		if (so_long->map[so_long->char_y][so_long->char_x] != 'E')
			so_long->map[so_long->char_y][so_long->char_x] = '0';
		so_long->char_x = x;
		so_long->char_y = y;
	}
}

void	check_collect(t_all *so_long, int x, int y)
{
	if (so_long->collect_game == 0)
		ft_exit(so_long);
	else
	{
		so_long->map[y][x] = 'T';
		so_long->map[so_long->char_y][so_long->char_x] = '0';
		so_long->char_x = x;
		so_long->char_y = y;
	}
}

void	game_loop2(t_all *so_long, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx_ptr,
		so_long->wdw_ptr, so_long->groundptr, x * 64, y * 64);
	if (so_long->map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx_ptr,
			so_long->wdw_ptr, so_long->wallptr, x * 64, y * 64);
	else if (so_long->map[y][x] == 'P')
		mlx_put_image_to_window(so_long->mlx_ptr,
			so_long->wdw_ptr, so_long->charptr, x * 64, y * 64);
	else if (so_long->map[y][x] == 'C')
		mlx_put_image_to_window(so_long->mlx_ptr,
			so_long->wdw_ptr, so_long->collectptr, x * 64, y * 64);
	else if (so_long->map[y][x] == 'E' && so_long->collect_game)
		mlx_put_image_to_window(so_long->mlx_ptr,
			so_long->wdw_ptr, so_long->exitoffptr, x * 64, y * 64);
	else if (so_long->map[y][x] == 'E' && so_long->collect_game == 0)
		mlx_put_image_to_window(so_long->mlx_ptr,
			so_long->wdw_ptr, so_long->exitonptr, x * 64, y * 64);
	else if (so_long->map[y][x] == 'T')
	{
		mlx_put_image_to_window(so_long->mlx_ptr,
			so_long->wdw_ptr, so_long->exitoffptr, x * 64, y * 64);
		mlx_put_image_to_window(so_long->mlx_ptr,
			so_long->wdw_ptr, so_long->charptr, x * 64, y * 64);
	}
}
