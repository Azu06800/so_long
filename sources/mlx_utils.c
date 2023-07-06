/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:13:59 by nihamdan          #+#    #+#             */
/*   Updated: 2023/07/05 20:23:01 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_mlx(t_all *so_long)
{
	so_long->mlx_ptr = mlx_init();
	so_long->wdw_ptr = mlx_new_window(so_long->mlx_ptr,
			so_long->map_length * 64, so_long->map_size * 64, "so_long");
	so_long->collect_game = count_collectibles(so_long);
	set_img(so_long);
}

void	set_img(t_all *so_long)
{
	so_long->charptr = get_img(so_long->mlx_ptr,
			so_long->charpath, so_long);
	so_long->wallptr = get_img(so_long->mlx_ptr,
			so_long->wallpath, so_long);
	so_long->groundptr = get_img(so_long->mlx_ptr,
			so_long->groundpath, so_long);
	so_long->collectptr = get_img(so_long->mlx_ptr,
			so_long->collectpath, so_long);
	so_long->exitonptr = get_img(so_long->mlx_ptr,
			so_long->exitonpath, so_long);
	so_long->exitoffptr = get_img(so_long->mlx_ptr,
			so_long->exitoffpath, so_long);
}

void	*get_img(void *mlx, char *path, t_all *so_long)
{
	void	*ptr;
	int		i;

	ptr = mlx_xpm_file_to_image(mlx, path, &i, &i);
	if (!ptr)
		ft_error("Error \nCannot open xpm\n", so_long);
	return (ptr);
}

int	game_loop(t_all *so_long)
{
	int	y;
	int	x;

	y = -1;
	while (so_long->map[++y])
	{
		x = -1;
		while (++x < so_long->map_length)
			game_loop2(so_long, x, y);
	}
	return (0);
}

int	key_press(int key, t_all *so_long)
{
	if (key == 53)
		ft_exit(so_long);
	else if (key == 13)
		move_char(so_long, so_long->char_x, so_long->char_y - 1);
	else if (key == 1)
		move_char(so_long, so_long->char_x, so_long->char_y + 1);
	else if (key == 0)
		move_char(so_long, so_long->char_x - 1, so_long->char_y);
	else if (key == 2)
		move_char(so_long, so_long->char_x + 1, so_long->char_y);
	return (EXIT_SUCCESS);
}
