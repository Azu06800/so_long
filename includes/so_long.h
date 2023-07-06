/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:03:26 by nihamdan          #+#    #+#             */
/*   Updated: 2023/07/05 19:54:12 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_all
{
	int		map_size;
	int		map_length;
	int		collectibles;
	int		exit_count;
	int		position_count;
	int		collectible_count;
	int		collect_game;
	int		flag_map;
	int		char_x;
	int		char_y;
	int		step;
	char	*exitoffpath;
	char	*exitonpath;
	char	*groundpath;
	char	*charpath;
	char	*collectpath;
	char	*wallpath;
	char	**map;
	char	**cpy_map;
	void	*mlx_ptr;
	void	*wdw_ptr;
	void	*exitoffptr;
	void	*exitonptr;
	void	*groundptr;
	void	*charptr;
	void	*collectptr;
	void	*wallptr;
}	t_all;

int		check_arg(int argc, char **argv);
int		is_rectangle(t_all *so_long);
int		is_closed(t_all *so_long);
int		check_path(t_all *so_long);
int		check_map(t_all *so_long);
int		check_map_specials(t_all *so_long);
int		map_format(t_all *so_long);
int		count_collectibles(t_all *so_long);
int		game_loop(t_all *so_long);
int		ft_exit(t_all *so_long);
int		key_press(int key, t_all *so_long);

size_t	ft_strlen_modif(char *s);

void	game_loop2(t_all *so_long, int x, int y);
void	move_char(t_all *so_long, int x, int y);
void	check_collect(t_all *so_long, int x, int y);
void	check_exit_position(t_all *so_long);
void	check_char_position(t_all *so_long);
void	ft_error(char *error, t_all *so_long);
void	map_size(t_all *so_long, char *argv);
void	init_map(t_all *so_long, char *argv);
void	cpy_map(t_all *so_long, char *argv);
void	map_fill(t_all *so_long, int j, int i, int *exit);
void	map_fill2(t_all *so_long, int j, int i, int *exit);
void	free_all(t_all *so_long);
void	init_so_long(t_all *so_long, char *argv);
void	init_mlx(t_all *so_long);
void	set_img(t_all *so_long);
void	*get_img(void *mlx, char *path, t_all *so_long);

#endif