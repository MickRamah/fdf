/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:07:44 by zramahaz          #+#    #+#             */
/*   Updated: 2024/08/08 10:10:36 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_get_color_a_b(t_dot *a, t_dot *b)
{
	if (a->color == -1)
	{
		if (a->z == 0)
			a->color = 0xffffff;
		else
			a->color = 0xFF4500;
	}
	if (b->color == -1)
	{
		if (b->z == 0)
			b->color = 0xffffff;
		else
			b->color = 0xFF4500;
	}
}

void	isometric(t_dot *dot, float angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

void	ft_set_param(t_dot *a, t_dot *b, t_dot *param)
{
	a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->z_scale;
	b->z *= param->z_scale;
	if (param->is_isometric)
	{
		isometric(a, param->angle);
		isometric(b, param->angle);
	}
	a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
}

void	trace_line(t_dot a, t_dot b, t_dot *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;
	int		pixels;

	ft_set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = ft_max(ft_abs(step_x), ft_abs(step_y));
	step_x /= max;
	step_y /= max;
	pixels = max;
	ft_get_color_a_b(&a, &b);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
		color = gradient(a.color, b.color, max, max - pixels);
		my_mlx_pixel_put(param, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		pixels = pixels - 1;
	}
}

void	ft_draw(t_dot **tab)
{
	int	x;
	int	y;
	int	width;
	int	height;

	height = 0;
	width = 0;
	ft_get_size_map(&height, &width, tab);
	y = 0;
	while (tab[y])
	{
		x = 0;
		while (x < width)
		{
			if (x < width - 1)
				trace_line(tab[y][x], tab[y][x + 1], &tab[0][0]);
			if (y < height - 1)
				trace_line(tab[y][x], tab[y + 1][x], &tab[0][0]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window((**tab).mlx, (**tab).win, (**tab).img, 0, 0);
}
