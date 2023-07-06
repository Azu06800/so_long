/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:34:20 by nihamdan          #+#    #+#             */
/*   Updated: 2023/07/05 19:50:51 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangle(t_all *so_long)
{
	int		i;
	size_t	size;

	i = 0;
	size = ft_strlen_modif(so_long->map[i++]);
	if (size <= 2)
	{
		ft_printf("Error\nMap is invalid !\n");
		return (EXIT_FAILURE);
	}
	so_long->map_length = size;
	while (so_long->map[i])
	{
		if (ft_strlen_modif(so_long->map[i++]) != size)
		{
			ft_printf("Error\nMap is not rectangular !\n");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	is_closed(t_all *so_long)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	j = -1;
	size = ft_strlen_modif(so_long->map[0]);
	while (++i < size)
	{
		if (so_long->map[0][i] != '1'
			|| so_long->map[so_long->map_size - 1][i] != '1')
		{
			ft_printf("Error\nMap is not closed !\n");
			return (EXIT_FAILURE);
		}
	}
	while (so_long->map[++j])
	{
		if (so_long->map[j][0] != '1' || so_long->map[j][size - 1] != '1')
		{
			ft_printf("Error\nMap is not closed !\n");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	check_map_specials(t_all *so_long)
{
	int	i;
	int	j;

	j = -1;
	so_long->exit_count = 0;
	so_long->position_count = 0;
	so_long->collectible_count = 0;
	while (so_long->map[++j])
	{
		i = -1;
		while (so_long->map[j][++i])
		{
			if (so_long->map[j][i] == 'P')
				so_long->position_count++;
			if (so_long->map[j][i] == 'E')
				so_long->exit_count++;
			if (so_long->map[j][i] == 'C')
				so_long->collectible_count++;
		}
	}
	if (so_long->exit_count == 1 && so_long->position_count == 1
		&& so_long->collectible_count > 0)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	check_path(t_all *so_long)
{
	int	i;
	int	j;
	int	exit;

	so_long->collectibles = count_collectibles(so_long);
	so_long->flag_map = 0;
	exit = 0;
	while (!so_long->flag_map)
	{
		so_long->flag_map = 1;
		j = -1;
		while (so_long->cpy_map[++j])
		{
			i = -1;
			while (so_long->cpy_map[j][++i])
				map_fill(so_long, j, i, &exit);
		}
	}
	if (exit == 1 && so_long->collectibles == 0)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	map_format(t_all *so_long)
{
	int	i;
	int	j;

	j = -1;
	while (so_long->map[++j])
	{
		i = -1;
		while (so_long->map[j][++i])
		{
			if (so_long->map[j][i] != '1' && so_long->map[j][i] != '0'
				&& so_long->map[j][i] != 'E' && so_long->map[j][i] != 'P'
					&& so_long->map[j][i] != 'C' && so_long->map[j][i] != '\n')
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
