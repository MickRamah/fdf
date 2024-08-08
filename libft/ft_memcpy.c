/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:03:57 by zramahaz          #+#    #+#             */
/*   Updated: 2024/02/28 15:27:24 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t size);

int	main()
{
	char src[5] = {'a', 'b', '\0', 'c', 'd'};
	char dest[20] = "Bonjour";
	char	*ptr;

	//ft_memcpy(dest, src, 5);
	ptr = memcpy(dest, src, 5);
	for (int i = 0; i < 20; i++)
		printf("%c ", ptr[i]);
	return (0);
}*/

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return ((void *)dest);
}
