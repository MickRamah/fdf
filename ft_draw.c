/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:07:44 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/23 16:12:17 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ABS(n) (n < 0 ? -n : n)
#define MAX(a, b) (a > b ? a : b)

// float   abs(float n)
// {
//     return (n < 0) ? -n : n;
// }

void	my_mlx_pixel_put(t_dot *param, int x, int y, int color)
{
	char	*dst;

	dst = param->data_addr + (y * param->line_length + x * (param->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    isometric(t_dot *dot, float angle)
{
    dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

void    ft_set_param(t_dot *a, t_dot *b, t_dot *param)
{
    // /*zoom*/
    a->x *= param->scale;
    a->y *= param->scale;
    b->x *= param->scale;
	b->y *= param->scale;
    a->z *= param->z_scale;
	b->z *= param->z_scale;

    /*Ajout 3D*/
    if (param->is_isometric)
	{
		isometric(a, param->angle);
		isometric(b, param->angle);
	}
    
    // translation
    a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
}

void    trace_line(t_dot a, t_dot b, t_dot *param)
{
    float   step_x;
    float   step_y;
    float   max;
    int		color;

    /*set-param*/
    ft_set_param(&a, &b, param);
    
    step_x = b.x - a.x;
    step_y = b.y - a.y;
    max = MAX(ABS(step_x), ABS(step_y));
    step_x /= max;
    step_y /= max;
    
    /*color*/
    color = (b.z || a.z) ? 0xfc0345 : 0xffffff;
	color = (b.z != a.z) ? 0xfc031c : color;
    
    while ((int)(a.x - b.x) || (int)(a.y - b.y))
    {
        my_mlx_pixel_put(param, a.x, a.y, color);
        a.x += step_x;
        a.y += step_y;
        if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
    }
}

void    ft_draw(t_dot **matrix)
{
    int x;
    int y;

    // ft_print_menu(PRM);
    y = 0;
    while (matrix[y])
    {
        x = 0;
        while (x < 19)
        {
            if (x < 18)
                trace_line(matrix[y][x], matrix[y][x + 1], &PRM);
            if (y < 10)
                trace_line(matrix[y][x], matrix[y + 1][x], &PRM);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(PRM.mlx_ptr, PRM.win_ptr, PRM.img, 0, 0);
}
