/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:21:49 by nihamdan          #+#    #+#             */
/*   Updated: 2023/07/05 20:11:11 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_arg(int argc, char **argv)
{
	int	size;
	int	fd;

	if (argc != 2)
	{
		ft_printf("Error \nso_long usage = [./so_long][MAP.ber]\n");
		return (EXIT_FAILURE);
	}
	size = ft_strlen(argv[1]);
	if (size < 4 || (argv[1][size - 4] != '.' || argv[1][size - 3] != 'b'
		|| argv[1][size - 2] != 'e' || argv[1][size - 1] != 'r'))
	{
		ft_printf("Error \nArgument must be [.ber] extension !\n");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error \nCannot open file !\n");
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	check_map(t_all *so_long)
{
	if (is_rectangle(so_long) || is_closed(so_long))
	{
		free_all(so_long);
		return (EXIT_FAILURE);
	}
	if (check_map_specials(so_long) || map_format(so_long))
	{
		free_all(so_long);
		ft_printf("Error \nMap doesn't have full requirements !\n");
		return (EXIT_FAILURE);
	}
	if (check_path(so_long))
	{
		free_all(so_long);
		ft_printf("Error \nThere is no valid path, please check the map !\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
