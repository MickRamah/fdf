/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:54:51 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/19 13:21:36 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct  s_fdf
{
    int height;
    int width;
    int **z_matrix;
    int zoom;
    int color;
    int x_translate;
    int y_translate;
    
    void    *mlx_ptr;
    void    *win_ptr;
}           t_fdf;

void    ft_read_file(char *file_name, t_fdf *data);
void    bresenham(float x, float y, float x1, float y1, t_fdf *data);
void    ft_draw(t_fdf *data);
void    ft_isometric(float *x, float *y, int z);

#endif