/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:52:20 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/07 12:04:23 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Parses each line of a .fdf file. Creates a new node for each element of the
file (separated by ' ') and adding it at the back of the t_fdf linked list
pointed at by 'fdf'
In case of failure, the list is freed and set to NULL*/
t_exit	parse_line(char *line, t_fdf **fdf, int y_counter)
{
	char	**line_split;
	char	**line_split_ptr;
	int		x_counter;
	t_fdf	*new_node;

	line_split = ft_split(line, ' ');
	line_split_ptr = line_split;
	x_counter = 0;
	while (*line_split_ptr)
	{
		new_node = ft_lstnew(x_counter++, y_counter,
				ft_atoi(*line_split_ptr), *(line_split_ptr + 1) == NULL);
		if (!new_node)
		{
			free_char_array(line_split);
			free(line);
			free_vectors(fdf);
			return (FAILURE);
		}
		line_split_ptr++;
		ft_lstadd_back(fdf, new_node);
	}
	free_char_array(line_split);
	return (SUCCESS);
}

/*Parses every line of a .fdf file using get_next_line(). Returns FAILURE if
the parsing of any line fails and SUCCESS if all the lines were successfully
The function loads all the data in a t_fdf linked list containing in each node
all 3 (x, y, z) coordinates of each point*/
t_exit	parse_fdf_file(int fd, t_fdf **fdf)
{
	char	*line;
	int		y_counter;

	*fdf = NULL;
	y_counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!parse_line(line, fdf, y_counter))
			return (FAILURE);
		y_counter++;
		free(line);
		line = get_next_line(fd);
	}
	return (SUCCESS);
}
