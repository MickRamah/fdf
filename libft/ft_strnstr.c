/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:15:02 by zramahaz          #+#    #+#             */
/*   Updated: 2024/03/03 11:57:49 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

int	main()
{
        char		*ptr1;
        char		*ptr2;

        ptr1 = ft_strnstr("fake you mum", "you", 10);
        ptr2 = ft_strnstr(((void*)0), "fake", 3);
	printf("ftstrnstr = %s\n", ptr1);
	printf("ft_strnstr = %s\n", ptr2);
	return (0);
}*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	n = ft_strlen(little);
	if (n == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (ft_strncmp(&big[i], little, n) == 0)
		{
			if (i + n > len)
				return (NULL);
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
