/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:34:32 by nihamdan          #+#    #+#             */
/*   Updated: 2023/07/06 18:00:41 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_all *so_long)
{
	int	j;

	j = -1;
	while (so_long->map[++j])
		free(so_long->map[j]);
	free(so_long->map[j]);
	free(so_long->map);
	return ;
}

void	free_cpy_map(t_all *so_long)
{
	int	j;

	j = -1;
	while (so_long->cpy_map[++j])
		free(so_long->cpy_map[j]);
	free(so_long->cpy_map[j]);
	free(so_long->cpy_map);
	return ;
}

void	free_all(t_all *so_long)
{
	free_map(so_long);
	free_cpy_map(so_long);
	return ;
}

void	ft_error(char *error, t_all *so_long)
{
	ft_printf("%s", error);
	if (so_long->groundptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->groundptr);
	if (so_long->wallptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->wallptr);
	if (so_long->charptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->charptr);
	if (so_long->exitonptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->exitonptr);
	if (so_long->exitoffptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->exitoffptr);
	if (so_long->collectptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->collectptr);
	mlx_destroy_window(so_long->mlx_ptr, so_long->wdw_ptr);
	free_all(so_long);
	//system ("leaks so_long");
	exit(EXIT_FAILURE);
}

int	ft_exit(t_all *so_long)
{
	mlx_destroy_image(so_long->mlx_ptr, so_long->groundptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->wallptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->charptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->exitonptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->exitoffptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->collectptr);
	mlx_destroy_window(so_long->mlx_ptr, so_long->wdw_ptr);
	free_all(so_long);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
