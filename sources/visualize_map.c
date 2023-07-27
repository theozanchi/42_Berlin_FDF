/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:11:34 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/27 18:38:20 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	return (length);
}

float	get_x_max(t_fdf **fdf)
{
	t_fdf	*ptr;
	int		x_max;

	ptr = *fdf;
	x_max = 0;
	while (ptr)
	{
		if (ptr->proj_data.x > x_max)
			x_max = ptr->proj_data.x;
		ptr = ptr->next;
	}
	return (x_max);
}

void	resize_map(t_fdf **fdf)
{
	t_fdf	*ptr;
	float	x_transformation_ratio;
	float	y_transformation_ratio;

	ptr = *fdf;
	x_transformation_ratio = (float)WIDTH / get_x_max(fdf);
	y_transformation_ratio = (float)HEIGHT / (float)WIDTH * x_transformation_ratio;
	while (ptr)
	{
		ptr->proj_data.x *= x_transformation_ratio;
		ptr->proj_data.y *= y_transformation_ratio;
		ptr = ptr->next;
	}
}

void	visualize_map(t_fdf **fdf, mlx_image_t *img)
{
	t_fdf	*ptr;
	t_fdf	*next_line_start;
	int		line_length;

	ptr = *fdf;
	next_line_start = ptr;
	line_length = get_line_length(fdf);
	while (ptr)
	{
		while (ptr && !ptr->end_of_line)
		{
			plot_line(ptr->proj_data, ptr->next->proj_data, img, 2);
			ptr = ptr->next;
		}
		if (next_line_start)
		{
			while (next_line_start && next_line_start->end_of_line)
				next_line_start = next_line_start->next;
			ptr = next_line_start;
			if (ptr)
				next_line_start = ptr->next;
		}
	}
}
