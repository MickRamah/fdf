/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:54:51 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/17 14:09:33 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct  s_fdf
{
    int height;
    int width;
    int **z_matrix;
    
    void    *mlx_ptr;
    void    *win_ptr;
}           t_fdf;

void    ft_read_file(char *file_name, t_fdf *data);

#endif