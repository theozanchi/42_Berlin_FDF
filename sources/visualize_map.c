/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:11:34 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/03 17:45:36 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	y_transformation_ratio = (float)HEIGTH / (float)WIDTH * x_transformation_ratio;
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
	int		line_len;

	ptr = *fdf;
	line_len = get_line_length(fdf);
	while (ptr)
	{
		if (!ptr->end_of_line)
			plot(ptr->proj_data, ptr->next->proj_data, img, 1, 0xFF0000FF);
		if (!is_last_line(ptr, line_len))
			plot(ptr->proj_data, get_nth_node(ptr, line_len)->proj_data,
				img, 2, 0x00FF00FF);
		ptr = ptr->next;
	}
}
