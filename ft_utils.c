/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:52:22 by zramahaz          #+#    #+#             */
/*   Updated: 2024/08/08 10:54:21 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_dot *param, int x, int y, int color)
{
	char	*dst;

	dst = param->data_addr + (y * param->size + x * (param->bpp / 8));
	*(unsigned int *)dst = color;
}

float	ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

float	ft_max(float a, float b)
{
	if (a < b)
		return (b);
	return (a);
}

void	ft_get_size_map(int	*height, int *width, t_dot **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	while (tab[0][j].is_last != 1)
		j++;
	*height = i;
	*width = j;
}

int	ft_close_window(t_dot **tab)
{
	int	i;

	i = 0;
	mlx_destroy_image(tab[0][0].mlx, tab[0][0].img);
	mlx_destroy_window(tab[0][0].mlx, tab[0][0].win);
	mlx_destroy_display(tab[0][0].mlx);
	free(tab[0][0].mlx);
	while (tab[i])
		free(tab[i++]);
	free(tab);
	exit(1);
}
