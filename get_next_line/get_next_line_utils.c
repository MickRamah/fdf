/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:12:32 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/27 10:26:26 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_extract_line(t_list_get *stash, char **line)
{
	int	i;
	int	j;

	ft_generate_line(stash, line);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i++];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	ft_generate_line(t_list_get *stash, char **line)
{
	int	i;
	int	count;

	count = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				count++;
				break ;
			}
			count++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (count + 1));
}

void	ft_clean_stash(t_list_get **stash)
{
	t_list_get	*last;
	t_list_get	*new;
	int			i;
	int			j;

	last = ft_get_last_list(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	new = malloc(sizeof(t_list_get));
	if (new == NULL)
		return ;
	new->next = NULL;
	new->content = malloc(ft_strlen_get(last->content) - i + 1);
	if (new->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		new->content[j++] = last->content[i++];
	new->content[j] = '\0';
	ft_free_stash(*stash);
	*stash = new;
}

int	ft_strlen_get(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_free_stash(t_list_get *stash)
{
	t_list_get	*last;
	t_list_get	*next;

	last = stash;
	while (last)
	{
		free(last->content);
		next = last->next;
		free(last);
		last = next;
	}
}
