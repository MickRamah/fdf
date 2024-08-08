/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:31:50 by zramahaz          #+#    #+#             */
/*   Updated: 2024/03/05 09:33:01 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t n, size_t size);

int	main(void)
{
	char	*s1;
	char	*s2;
	int	i;

	s1 = (char *)calloc(10, sizeof(char));
	s2 = (char *)ft_calloc(10, sizeof(char));
	i = -1;
	while (++i < 20)
		printf("adress = %p et s[%d]= %c\n", &s1[i], i, s1[i]);
	i = -1;
	printf("\n");
	while (++i < 20)
		printf("adress = %p et s[%d]= %c\n", &s2[i], i, s2[i]);
	return (0);
}*/

void	*ft_calloc(size_t n, size_t size)
{
	void	*str;

	str = malloc(size * n);
	if (!str)
		return (NULL);
	ft_bzero(str, n * size);
	return (str);
}
