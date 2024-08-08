/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:33:58 by zramahaz          #+#    #+#             */
/*   Updated: 2024/02/25 15:56:12 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <stdio.h>

void	*ft_memset(void *str, int c, size_t size);

int	main(void)
{
	char	str[20] = "bonjour";
	int	c = 'a';

	ft_memset(str, c, 3);
	printf("%s", str);
	return (0);
}*/

void	*ft_memset(void *str, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*(unsigned char *)(str + i) = (unsigned char)c;
		i++;
	}
	return ((void *)str);
}
