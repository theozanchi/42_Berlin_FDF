/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:52:20 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/18 20:16:35 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_exit	parse_line(char *line, t_map **map, int x_counter)
{
	char	**line_split;
	char	**line_split_ptr;
	int		y_counter;
	t_map	*new_node;

	line_split = ft_split(line, ' ');
	line_split_ptr = line_split;
	y_counter = 0;
	while (*line_split_ptr)
	{
		new_node = ft_lstnew(x_counter, y_counter++,
				ft_atoi(*line_split_ptr), *(line_split_ptr + 1) == NULL);
		if (!new_node)
		{
			free_char_array(line_split);
			free(line);
			free_map(map);
			return (FAILURE);
		}
		line_split_ptr++;
		ft_lstadd_back(map, new_node);
	}
	free_char_array(line_split);
	return (SUCCESS);
}

t_exit	parse_map(int fd, t_map **map)
{
	char	*line;
	int		x_counter;

	*map = NULL;
	x_counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!parse_line(line, map, x_counter))
			return (FAILURE);
		x_counter++;
		free(line);
		line = get_next_line(fd);
	}
	return (SUCCESS);
}
