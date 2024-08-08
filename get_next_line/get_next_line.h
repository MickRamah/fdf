/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:11:01 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/27 10:25:09 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list_get
{
	char				*content;
	struct s_list_get	*next;
}					t_list_get;

char		*get_next_line(int fd);

void		ft_read_and_stash(int fd, t_list_get **stash);
void		ft_add_to_stash(t_list_get **stash, char *buffer, int count);
void		ft_extract_line(t_list_get *stash, char **line);
void		ft_generate_line(t_list_get *stash, char **line);
void		ft_clean_stash(t_list_get **stash);
void		ft_free_stash(t_list_get *stash);

t_list_get	*ft_get_last_list(t_list_get *stash);

int			ft_found_newline(t_list_get *stash);
int			ft_strlen_get(char *s);

#endif
