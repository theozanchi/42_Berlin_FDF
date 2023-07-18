/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:52:20 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/18 17:33:04 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_exit	parse_map(int fd, t_map **map)
{
	char	*line;
	char	**line_split;
	t_map	**ptr;
	t_map	*node;
	int		x_counter;
	int		y_counter;

	*map = NULL;
	ptr = map;
	x_counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_split = ft_split(line, ' ');
		y_counter = 0;
		while (*line_split)
		{
			node = malloc(sizeof(t_map));
			if (!node)
			{
				free_char_array(line_split);
				free(line);
				free_map(*map);
				return (FAILURE);
			}
			node->x = x_counter;
			node->y = y_counter++;
			node->z = ft_atoi(*line_split++);
			node->end_of_line = (*line_split == NULL);
			node->next = NULL;
			*ptr = node;
			ptr = &(node->next);
		}
		x_counter++;
		free_char_array(line_split);
		free(line);
		line = get_next_line(fd);
	}
	return (SUCCESS);
}
