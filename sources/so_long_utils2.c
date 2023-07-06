/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:54:37 by nihamdan          #+#    #+#             */
/*   Updated: 2023/07/06 19:35:04 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlen_modif(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	map_size(t_all *so_long, char *argv)
{
	int		fd;
	char	*line;

	so_long->map_size = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		so_long->map_size++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return ;
}

void	init_map(t_all *so_long, char *argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	map_size(so_long, argv);
	so_long->map = malloc((so_long->map_size + 1) * sizeof(char *));
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (i != so_long->map_size)
	{
		so_long->map[i++] = line;
		line = get_next_line(fd);
	}
	so_long->map[i] = NULL;
	close(fd);
	return ;
}

void	cpy_map(t_all *so_long, char *argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	map_size(so_long, argv);
	so_long->cpy_map = malloc((so_long->map_size + 1) * sizeof(char *));
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		so_long->cpy_map[i++] = line;
		line = get_next_line(fd);
	}
	so_long->cpy_map[i] = NULL;
	close(fd);
	return ;
}

int	count_collectibles(t_all *so_long)
{
	int	i;
	int	j;
	int	c;

	j = -1;
	c = 0;
	while (so_long->map[++j])
	{
		i = -1;
		while (so_long->map[j][++i])
		{
			if (so_long->map[j][i] == 'C')
				c++;
		}
	}
	return (c);
}
