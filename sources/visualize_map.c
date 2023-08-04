/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:11:34 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/04 16:17:37 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_resize_map(t_fdf **fdf)
{
	t_fdf		*ptr;
	t_extrema	extrema;
	float		x_transformation_ratio;
	float		y_transformation_ratio;

	ptr = *fdf;
	extrema = get_extrema(fdf);
	x_transformation_ratio = (float)WIDTH / get_x_max(fdf);
	y_transformation_ratio = (float)HEIGTH / (float)WIDTH * x_transformation_ratio;
	while (ptr)
	{
		ptr->proj_data.x *= x_transformation_ratio;
		ptr->proj_data.y *= y_transformation_ratio;
		ptr = ptr->next;
	}
}

/*Resizes the projected map by strecthing x_values to make them fit the WIDTH
of the image. 'fdf->proj_data' is updated for each node of the list pointed at
by 'fdf'*/
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

/*Loops through the list pointed at by 'fdf' and connects all nodes to the
surrounding nodes (top, down, left and right)*/
void	visualize_map(t_fdf **fdf, mlx_image_t *img)
{
	t_fdf	*ptr;
	int		line_len;

	ptr = *fdf;
	line_len = get_line_length(fdf);
	while (ptr)
	{
		if (!ptr->end_of_line)
			plot(ptr->proj_data, ptr->next->proj_data, img, 0xFF0000FF);
		if (!is_last_line(ptr, line_len))
			plot(ptr->proj_data, get_nth_node(ptr, line_len)->proj_data,
				img, 0x00FF00FF);
		ptr = ptr->next;
	}
}
