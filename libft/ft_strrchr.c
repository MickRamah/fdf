/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:25:34 by zramahaz          #+#    #+#             */
/*   Updated: 2024/02/28 16:41:56 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s1 = "Bonjour\0 Mick \0 et";
	char	*d1;
	char	*d2;
	int	i;

	d1 = strrchr(s1, 'o');
	d2 = ft_strrchr(s1 , 'o');
	i = -1;
	while (++i < 13)
		printf("d1[%d] = %c\n", i, d1[i]);
	printf("\n");
	i = -1;
	while (++i < 13)
		printf("d2[%d] = %c\n", i, d2[i]);
	if (d1 = d2)
		printf("Vrai\n");
	else
		printf("Faux\n");
	return (0);
}*/

char	*ft_strrchr(const char *src, int c)
{
	size_t	i;

	i = ft_strlen(src);
	while (src[i] != (char)c && i)
		i--;
	if (src[i] == (char)c)
		return ((char *)src + i);
	return (NULL);
}
