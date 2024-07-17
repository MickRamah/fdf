/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdcounter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:52:22 by vinograd          #+#    #+#             */
/*   Updated: 2024/07/17 14:26:51 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int		ft_wdcounter(char const *str, char c)
// {
// 	int i;
// 	int words;

// 	words = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		while (str[i] == c && str[i] != '\0')
// 			i++;
// 		if (str[i])
// 		words++;
// 	 	while (str[i] != c && str[i] != '\0')
// 			i++;
// 	}
// 	return (words);
// }

int	ft_wdcounter(char const *s, char c)
{
	int	i;
	int	nb_strs;

	i = 0;
	nb_strs = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}
