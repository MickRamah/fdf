/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:54:51 by zramahaz          #+#    #+#             */
/*   Updated: 2024/08/08 08:54:48 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"

typedef struct s_dot
{
	float			x;
	float			y;
	float			z;
	int				color;
	int				is_last;
	int				win_x;
	int				win_y;
	int				scale;
	int				z_scale;
	int				is_isometric;
	double			angle;
	int				shift_x;
	int				shift_y;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bpp;
	int				size;
	int				e;
}					t_dot;

t_dot			**read_map(char *file_name);
void			ft_draw(t_dot **tab);
void			ft_print_menu(t_dot param);
void			trace_line(t_dot a, t_dot b, t_dot *param);
void			my_mlx_pixel_put(t_dot *param, int x, int y, int color);
void			ft_get_size_map(int	*height, int *width, t_dot **tab);
void			ft_close_window(t_dot **tab);
unsigned int	ft_atoi_base(const char *str, const char *base);

int				gradient(int startcolor, int endcolor, int len, int pix);

float			ft_abs(float n);
float			ft_max(float a, float b);

#endif
