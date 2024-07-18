/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:07:44 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/18 16:39:21 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// #define MAX(a, b) (a > b ? a : b)
#define ABS(n) (n < 0 ? -n : n)

// float   abs(float n)
// {
//     return (n < 0) ? -n : n;
// }

void    ft_isometric(float *x, float *y, int z)
{
    int tmp;

    tmp = *x;
    *x = (tmp - *y) * cos(0.523599);
    *y = (tmp + *y) * sin(0.523599) - z;
}

void    bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
    float   x_step;   
    float   y_step;
    int     max;
    int     z;
    int     z1;
    
    z = data->z_matrix[(int)y][(int)x];
    z1 = data->z_matrix[(int)y1][(int)x1];
    
    //zoom
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;
    
    //couleur
    data->color = (z || z1) ? 0xe80c0c : 0xffffff;
    
    // Ajout 3D
    ft_isometric(&x, &y, z);
    ft_isometric(&x1, &y1, z1);

    x += data->shift_x;
    y += data->shift_y;
    x1 += data->shift_x;
    y1 += data->shift_y;
        
    x_step = x1 - x;
    y_step = y1 - y;

    max = MAX(ABS(x_step), ABS(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_step;
        y += y_step;
    }
}

void    ft_draw(t_fdf *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            // line = -> (horizontale)
            if (x < data->width - 1)
                bresenham(x, y, x + 1 , y, data);
            // line = | (verticale)
            if (y < data->height - 1)
                bresenham(x, y, x , y + 1, data);
            x++;
        }
        y++;
    }
}