/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:17:09 by zramahaz          #+#    #+#             */
/*   Updated: 2024/08/08 10:13:30 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// gcc *.c get_next_line/*.c  libft/libft.a minilibx-linux/libmlx.a -lX11 -lm -lXext

void	ft_do_it(int key, t_dot **tab)
{
	if (key == 65451)
		if (tab[0][0].scale < 100)
			tab[0][0].scale += 1;
	if (key == 65453)
		if (tab[0][0].scale > 2)
			tab[0][0].scale -= 1;
	if (key == 65362)
		if (tab[0][0].z_scale < 50)
			tab[0][0].z_scale += 1;
	if (key == 65364)
		if (tab[0][0].z_scale > -50)
			tab[0][0].z_scale -= 1;
	if (key == 97)
		tab[0][0].shift_x -= 10;
	if (key == 100)
		tab[0][0].shift_x += 10;
	if (key == 119)
		tab[0][0].shift_y -= 10;
	if (key == 115)
		tab[0][0].shift_y += 10;
	if (key == 65433)
		tab[0][0].angle += 0.05;
	if (key == 65431)
		tab[0][0].angle -= 0.05;
}

int	is_key(int key)
{
	return (key == 65453 || key == 65451 || key == 65362 || key == 65364 || \
	key == 97 || key == 100 || key == 119 || key == 115 || key == 65431 || \
	key == 65433);
}

int	deal_key(int key, t_dot **tab)
{
	if (is_key(key))
	{
		mlx_destroy_image(tab[0][0].mlx, tab[0][0].img);
		mlx_clear_window(tab[0][0].mlx, tab[0][0].win);
		tab[0][0].img = \
		mlx_new_image(tab[0][0].mlx, tab[0][0].win_x, tab[0][0].win_y);
		tab[0][0].data_addr = \
		mlx_get_data_addr((**tab).img, &(**tab).bpp, &(**tab).size, &(**tab).e);
		ft_do_it(key, tab);
		ft_draw(tab);
	}
	if (key == 65307)
		ft_close_window(tab);
	return (0);
}

void	set_default(t_dot *param)
{
	param->scale = 2;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx = mlx_init();
	param->win = \
	mlx_new_window(param->mlx, param->win_x, param->win_y, "FDF");
	param->img = \
	mlx_new_image(param->mlx, param->win_x, param->win_y);
	param->data_addr = \
	mlx_get_data_addr(param->img, &param->bpp, &param->size, &param->e);
}

int	main(int argc, char **argv)
{
	t_dot	**tab;

	if (argc != 2)
	{
		write(1, "usage: ./fdf <file_map>\n", 24);
		exit(0);
	}
	tab = read_map(argv[1]);
	set_default(&tab[0][0]);
	ft_draw(tab);
	mlx_key_hook(tab[0][0].win, deal_key, tab);
	mlx_loop(tab[0][0].mlx);
	return (0);
}
