/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:17:09 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/17 15:00:12 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    t_fdf   *data;

    data = (t_fdf *)malloc(sizeof(t_fdf));
    ft_read_file(argv[1], data);
    
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
    return (0);
}