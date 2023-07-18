/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:52:20 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/18 17:15:41 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_exit	parse_map(int fd, t_map **map)
{
	char	*line;
	char	**line_split;
	t_map	*ptr;
	int		x_counter;
	int		y_counter;

	*map = malloc(sizeof(t_map *));
	if (!*map)
		return (FAILURE);
	ptr = *map;
	x_counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_split = ft_split(line, ' ');
		y_counter = 0;
		while (*line_split)
		{
			ptr->x = x_counter;
			ptr->y = y_counter++;
			ptr->z = ft_atoi(*line_split++);
			ptr->end_of_line = FALSE;
			ptr->next = malloc(sizeof(t_map));
			ptr = ptr->next;
		}
		ptr->end_of_line = TRUE;
		x_counter++;
		free_char_array(line_split);
		free(line);
		line = get_next_line(fd);
	}
	ptr->next = NULL;
	return (SUCCESS);
}
