/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:05:11 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/04 17:20:55 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Returns true if the node pointed at by 'fdf' corresponds to a point in the
last line of the .fdf file*/
t_bool	is_last_line(t_fdf *fdf, int line_length)
{
	while (line_length--)
	{
		if (!fdf->next)
			return (TRUE);
		fdf = fdf->next;
	}
	return (FALSE);
}

/*Returns the length of lines of the fdf data stored inside the list pointed
at by 'fdf'*/
int	get_line_length(t_fdf **fdf)
{
	t_fdf	*ptr;
	int		length;

	ptr = *fdf;
	length = 0;
	while (!ptr->end_of_line)
	{
		length++;
		ptr = ptr->next;
	}
	return (length + 1);
}

/*Returns the extrema values of the projected data stored in the list pointed at
by 'fdf': 
• x_min
• y_min
• x_max
• y_max*/
t_extrema	get_extrema(t_fdf **fdf)
{
	t_extrema	output;
	t_fdf		*ptr;

	output.x_min = (float)INT_MAX;
	output.x_max = (float)INT_MIN;
	output.y_min = (float)INT_MAX;
	output.y_max = (float)INT_MIN;
	ptr = *fdf;
	while (ptr)
	{
		if (ptr->proj_data.x < output.x_min)
			output.x_min = ptr->proj_data.x;
		if (ptr->proj_data.x > output.x_max)
			output.x_max = ptr->proj_data.x;
		if (ptr->proj_data.y < output.y_min)
			output.y_min = ptr->proj_data.y;
		if (ptr->proj_data.y > output.y_max)
			output.y_max = ptr->proj_data.y;
		ptr = ptr->next;
	}
	return (output);
}
