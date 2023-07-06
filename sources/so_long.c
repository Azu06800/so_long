/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:17:46 by nihamdan          #+#    #+#             */
/*   Updated: 2023/07/05 18:04:32 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_all	so_long;

	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	init_so_long(&so_long, argv[1]);
	if (check_map(&so_long))
		return (EXIT_FAILURE);
	check_char_position(&so_long);
	init_mlx(&so_long);
	mlx_loop_hook(so_long.mlx_ptr, &game_loop, &so_long);
	mlx_hook(so_long.wdw_ptr, 2, 0, &key_press, &so_long);
	mlx_hook(so_long.wdw_ptr, 17, 0, &ft_exit, &so_long);
	mlx_loop(so_long.mlx_ptr);
	return (EXIT_SUCCESS);
}
