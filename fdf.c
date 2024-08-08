/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:17:09 by zramahaz          #+#    #+#             */
/*   Updated: 2024/08/08 15:05:58 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_dot **tab)
{
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
	param->win_x = 1920;
	param->win_y = 1080;
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
	int		fd;

	if (argc != 2)
	{
		write(1, "usage: ./fdf <file_map>\n", 24);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		close(fd);
		return (1);
	}
	close(fd);
	tab = ft_read_map(argv[1]);
	set_default(&tab[0][0]);
	ft_draw(tab);
	mlx_key_hook(tab[0][0].win, deal_key, tab);
	mlx_hook(tab[0][0].win, 17, 0, ft_close_window, tab);
	mlx_loop(tab[0][0].mlx);
	return (0);
}
