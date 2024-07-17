/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:33:08 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/17 14:59:55 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_read_file(char *file_name, t_fdf *data)
{
    int i;
    int fd;
    char    *line;
    
    data->height = ft_get_height(file_name);
    data->width = ft_get_width(file_name);
    data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
    i = 0;
    while (i <= data->height)
        data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
    fd = open(file_name, O_RDONLY, 0);
    i = 0;
    while (get_next_line(fd, &line))
    {
        ft_fill_matrix(data->z_matrix[i], line);    
        free(line);
        i++;
    }
    close(fd);
    data->z_matrix[i] = NULL;
}

int ft_get_height(char *file_name)
{
    int fd;
    int height;
    char    *line;
    
    fd = open(file_name, O_RDONLY, 0);
    height = 0;
    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    return (height);
}

int ft_get_width(char *file_name)
{
    int fd;
    int width;
    char    *line;

    width = 0;
    fd = open(file_name, O_RDONLY, 0);
    get_next_line(fd, &line);
    width = ft_wdcounter(line, ' ');
    free(line);
    close(fd);
    return (width);
}

void    ft_fill_matrix(int *z_line, char *line)
{
    char **nums;
    int i;

    nums = ft_strsplit(line, ' ');
    i = 0;
    while (nums[i])
    {
        z_line[i] = ft_atoi(nums[i]);
        free(nums[i]);
        i++;
    }
    free(nums);
}