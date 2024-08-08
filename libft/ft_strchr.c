/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:06:49 by zramahaz          #+#    #+#             */
/*   Updated: 2024/02/28 16:38:21 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	int	i;
	char	*src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
 	char	*d1 = strchr(src, 'e');
 	char	*d2 = ft_strchr(src, 'e');
 
 	if (d1 == d2)
 		printf("Vrai\n");
 	else
		printf("Faux\n");
	i = -1;
	while (++i < 28)
		printf("d1[%d] = %c\n", i, d1[i]);
	printf("\n");
	i = -1;
	while (++i < 28)
		printf("d2[%d] = %c\n", i, d2[i]);
	printf("\n");


	return (0);
}*/

char	*ft_strchr(const char *src, int c)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != (char)c)
		i++;
	if (src[i] == (char)c)
		return ((char *)src + i);
	return (NULL);
}
