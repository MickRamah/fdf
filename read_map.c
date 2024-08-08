/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:33:08 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/27 15:43:32 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_dot	**ft_allocate(int x, int y)
{
	t_dot	**new;

	new = (t_dot **)malloc(sizeof(t_dot *) * (y + 1));
	if (new == NULL)
		exit(0);
	while (y > 0)
	{
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
		if (new[y] == NULL)
			exit(0);
	}
	return (new);
}

static int	ft_count_strs(char const *s, char c)
{
	size_t	i;
	size_t	nb_strs;

	i = 0;
	nb_strs = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

t_dot	**memory_allocete(char *file_name)
{
	t_dot	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit(0);
	line = get_next_line(fd);
	x = ft_count_strs(line, ' ');
	free(line);
	y = 0;
	while (1)
	{
		y++;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	new = ft_allocate(x, y);
	close(fd);
	return (new);
}

int	get_dots_from_line(char *line, t_dot **tab, int y)
{
	char	**dots;
	int		x;
	int		j;

	dots = ft_split(line, ' ');
	x = 0;
	while (dots[x])
	{
		tab[y][x].z = ft_atoi(dots[x]);
		tab[y][x].x = x;
		tab[y][x].y = y;
		j = 0;
		while (dots[x][j] && dots[x][j] != ',')
			j++;
		if (dots[x][j] == ',')
			tab[y][x].color = ft_atoi_base(&dots[x][++j], "0123456789ABCDEF");
		else
			tab[y][x].color = -1;
		tab[y][x].is_last = 0;
		free(dots[x++]);
	}
	tab[y][x].is_last = 1;
	free(dots);
	free(line);
	return (x);
}

t_dot	**read_map(char *file_name)
{
	t_dot	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	matrix_of_dots = (t_dot **)memory_allocete(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		get_dots_from_line(line, matrix_of_dots, y++);
	}
	free(line);
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}
