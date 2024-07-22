/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:54:51 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/22 13:03:01 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define PRM matrix[0][0]

typedef struct  s_dot
{
    float		x;
	float		y;
	float       z;

	int			win_x;
	int			win_y;
	int			scale;
	int			z_scale;
	int			is_last;
	int			is_isometric;
	double		angle;
	int			shift_x;
	int			shift_y;

    void		*mlx_ptr;
	void		*win_ptr;
}   t_dot;

t_dot			**read_map(char *file_name);
void    ft_draw(t_dot **matrix);
void	ft_print_menu(t_dot param);
void    trace_line(t_dot a, t_dot b, t_dot *param);

#endif