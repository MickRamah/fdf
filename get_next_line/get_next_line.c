/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:09:39 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/27 10:25:52 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list_get	*stash = NULL;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	ft_read_and_stash(fd, &stash);
	if (!stash)
		return (NULL);
	ft_extract_line(stash, &line);
	ft_clean_stash(&stash);
	if (line[0] == '\0')
	{
		free(line);
		ft_free_stash(stash);
		stash = NULL;
		return (NULL);
	}
	return (line);
}

void	ft_read_and_stash(int fd, t_list_get **stash)
{
	int		count;
	char	*buffer;

	count = 1;
	while (count && !ft_found_newline(*stash))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		count = (int)read(fd, buffer, BUFFER_SIZE);
		if ((count == 0 && *stash == NULL) || count == -1)
		{
			free(buffer);
			return ;
		}
		buffer[count] = '\0';
		ft_add_to_stash(stash, buffer, count);
		free (buffer);
	}
}

void	ft_add_to_stash(t_list_get **stash, char *buffer, int count)
{
	t_list_get	*new;
	t_list_get	*last;
	int			i;

	new = malloc(sizeof(t_list_get));
	if (new == NULL)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (count + 1));
	if (new->content == NULL)
		return ;
	i = 0;
	while (i < count && buffer[i])
	{
		new->content[i] = buffer[i];
		i++;
	}
	new->content[count] = '\0';
	if (*stash == NULL)
		*stash = new;
	else
	{
		last = ft_get_last_list(*stash);
		last->next = new;
	}
}

t_list_get	*ft_get_last_list(t_list_get *stash)
{
	t_list_get	*last;

	last = stash;
	while (last->next)
		last = last->next;
	return (last);
}

int	ft_found_newline(t_list_get *stash)
{
	t_list_get	*last;
	int			i;

	if (stash == NULL)
		return (0);
	last = ft_get_last_list(stash);
	i = 0;
	while (last->content[i])
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
