/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:17:09 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/23 16:05:07 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// -lmlx -lXext- lX11
//cc *.c -L../Libft -lft -L../minilibx-linux
// -lmlx -lXext -lX11 -lm -o fdf
// gcc *.c libft/libft.a minilibx-linux/libmlx.a -lX11 -lm -lXext

void    ft_do_it(int key, t_dot **matrix)
{
    if (key == 65451)
        PRM.scale += 3;
    if (key == 65453)
        PRM.scale -= 3;
    if (key == 65362)
        PRM.z_scale += 1;
    if (key == 65364)
        PRM.z_scale -= 1;
    if (key == 97)
        PRM.shift_x -= 10;
    if (key == 100)
        PRM.shift_x += 10;
    if (key == 119)
        PRM.shift_y -= 10;
    if (key == 115)
        PRM.shift_y += 10;
    if (key == 65433)
        PRM.angle += 0.05;
    if (key == 65431)
        PRM.angle -= 0.05;
        
}

int    is_key(int key)
{
    return (key == 65453 || key == 65451 || key == 65362 || key == 65364 || \
    key == 97 || key == 100 || key == 119 || key == 115 || key == 65431 || \
    key == 65433);
}

int    deal_key(int key, t_dot **matrix)
{
    ft_printf("%d\n", key);
    if (is_key(key))
    {
        mlx_destroy_image(PRM.mlx_ptr, PRM.img);
        mlx_clear_window(PRM.mlx_ptr, PRM.win_ptr);
        
        PRM.img =\
    mlx_new_image(PRM.mlx_ptr, PRM.win_x, PRM.win_y);
        PRM.data_addr =\
    mlx_get_data_addr(PRM.img, &PRM.bits_per_pixel, &PRM.line_length, &PRM.endian);
    
        ft_do_it(key, matrix);
        ft_draw(matrix);
    }
    if (key == 65307)
    {
        int i;
        /*free*/
        mlx_destroy_image(PRM.mlx_ptr, PRM.img);
	    mlx_destroy_window(PRM.mlx_ptr, PRM.win_ptr);
	    mlx_destroy_display(PRM.mlx_ptr);
        free(PRM.mlx_ptr);
        i = 0;
        while (matrix[i])
            free(matrix[i++]);
        free(matrix);
		exit(0);
    }
    return (0);
}

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 2000; // longueur du fenetre
	param->win_y = 1000; // largeur du fenetre
	param->shift_x = param->win_x / 3; // point de depart suivant x
	param->shift_y = param->win_y / 3; // point de depart suivant y
	param->mlx_ptr = mlx_init();
	param->win_ptr =\
    mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
    param->img =\
    mlx_new_image(param->mlx_ptr, param->win_x, param->win_y);
    param->data_addr =\
    mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->line_length, &param->endian);
}

int main(int argc, char **argv)
{
    t_dot	**matrix;

    if (argc != 2)
    {
        ft_printf("usage: ./fdf <file_map>\n");
        exit(0);
    }
    matrix = read_map(argv[1]); // allocation
    // printf("data.height = %d\n", data.height);
    printf("data.width = %d\n", matrix[0][0].is_last);
    set_default(&PRM);
    ft_draw(matrix);
    mlx_key_hook(PRM.win_ptr, deal_key, matrix);
    mlx_loop(PRM.mlx_ptr); // pour garder la fenetre ouverte
    return (0);
}
