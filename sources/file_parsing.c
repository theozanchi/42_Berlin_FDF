/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:52:20 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/15 17:42:12 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Checks if a hex colour code (starting with '0x') is present in the string
'str' and if so, updates node->colour accordingly. If not, node->colour is set
to black (0x000000FF)*/
void	parse_colour(t_fdf *node, char **str)
{
	char	*colour;

	if (ft_strnstr(*str, "0x", ft_strlen(*str)))
	{
		colour = ft_strjoin(ft_strnstr(*str, "0x", ft_strlen(*str)), "FF");
		node->colour = ft_strtoui(colour, 0);
		free(colour);
	}
	else
		node->colour = 0x000000FF;
}

/*Parses each line of a .fdf file. Creates a new node for each element of the
file (separated by ' ') and adding it at the back of the t_fdf linked list
pointed at by 'fdf'
In case of failure, the list is freed and set to NULL*/
t_exit	parse_line(char *line, t_fdf **fdf, int y_counter)
{
	char	**line_split;
	char	**ptr;
	int		x_cnt;
	t_fdf	*node;

	line_split = ft_split(line, ' ');
	ptr = line_split;
	x_cnt = 0;
	while (*ptr)
	{
		node = ft_lstnew(x_cnt++, y_counter, ft_atoi(*ptr), *(ptr + 1) == NULL);
		if (!node)
		{
			free_char_array(line_split);
			free(line);
			free_vectors(fdf);
			return (FAILURE);
		}
		parse_colour(node, ptr++);
		ft_lstadd_back(fdf, node);
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
