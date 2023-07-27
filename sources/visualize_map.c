/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:11:34 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/27 12:46:46 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_x_max(t_fdf **fdf)
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
	int		x_transformation_ratio;
	int		y_transformation_ratio;

	ptr = *fdf;
	x_transformation_ratio = WIDTH / get_x_max(fdf);
	y_transformation_ratio = HEIGHT / WIDTH * x_transformation_ratio;
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

	ptr = *fdf;
	next_line_start = ptr;
	while (ptr)
	{
		while (ptr && !ptr->end_of_line)
		{
			plot_line(ptr->proj_data, ptr->next->proj_data, img);
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
