/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:17:09 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/19 15:15:40 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// -lmlx -lXext- lX11
//cc *.c -L../Libft -lft -L../minilibx-linux
// -lmlx -lXext -lX11 -lm -o fdf
// gcc *.c libft/libft.a minilibx-linux/libmlx.a -lX11 -lm -lXext

int deal_key(int key, t_fdf *data)
{
    ft_printf("%d\n", key);
    if (key == 65363)
        data->x_translate += 10;
    if (key == 65361)
        data->x_translate -= 10;
    if (key == 65364)
        data->y_translate += 10;
    if (key == 65362)
        data->y_translate -= 10;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    ft_draw(data);
    return (0);
}

int main(int argc, char **argv)
{
    t_fdf   *data;

    data = (t_fdf *)malloc(sizeof(t_fdf));
    ft_read_file(argv[1], data);

    // affichage tableau z_matrice
    int i;
    int j;

    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            ft_printf("%3d ", data->z_matrix[i][j]);
            j++;
        }
        i++;
        ft_printf("\n");
    }
    
    // zoom
    data->zoom = 20;
    data->x_translate = 200;
    data->y_translate = 50;
    
    // Ici nous initialisons la fenetre
    data->mlx_ptr = mlx_init();
    
    // C'est pour ouvrir la fenetre de taille h = 1000 et l = 1000
    // nomme "FDF".
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
    
    // dessiner une line
        // bresenham(10, 10, 600, 300, data);
        
    // dessiner data->z_matrice
    ft_draw(data);
    
    // pour la partie BONUS
    //      une fonction qui va nous permettre d'imprimer un
    //      message a chaque fois que nous appuierons sur une touche.
    mlx_key_hook(data->win_ptr, deal_key, data);
    
    // une fonction que fait durer la fenetre, c'est comme une 
    // boucle infini
    mlx_loop(data->mlx_ptr);
    return (0);
}
