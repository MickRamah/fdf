/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:22:22 by zramahaz          #+#    #+#             */
/*   Updated: 2024/08/08 10:07:36 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_round(double num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= .5)
		rounded++;
	return (rounded);
}

int	gradient(int color_i, int color_f, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	if (color_i == color_f)
		return (color_i);
	increment[0] = (double)((color_f >> 16) - (color_i >> 16)) / (double)len;
	increment[1] = (double)(((color_f >> 8) & 0xFF) - ((color_i >> 8) & 0xFF));
	increment[1] /= (double)len;
	increment[2] = (double)((color_f & 0xFF) - (color_i & 0xFF)) / (double)len;
	new[0] = (color_i >> 16) + ft_round(pix * increment[0]);
	new[1] = ((color_i >> 8) & 0xFF) + ft_round(pix * increment[1]);
	new[2] = (color_i & 0xFF) + ft_round(pix * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}
