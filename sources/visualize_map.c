/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:11:34 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/04 17:21:35 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Loops through the list pointed at by 'fdf' and brings all x and y values of
proj_data into the frame by moving them of x_min up on the x axis if x_min is
negative and by y_min up on the y axis if y_min is negative*/
void	move_map_to_frame(t_fdf **fdf, t_extrema *extrema)
{
	t_fdf	*ptr;

	ptr = *fdf;
	if (extrema->x_min > 0 && extrema->y_min > 0)
		return ;
	while (ptr)
	{
		if (extrema->x_min < 0)
			ptr->proj_data.x -= extrema->x_min;
		if (extrema->y_min < 0)
			ptr->proj_data.y -= extrema->y_min;
		ptr = ptr->next;
	}
}

/**/
void	new_resize_map(t_fdf **fdf)
{
	t_fdf		*ptr;
	t_extrema	extrema;
	float		x_transf_ratio;
	float		y_transf_ratio;

	ptr = *fdf;
	extrema = get_extrema(fdf);
	move_map_to_frame(fdf, &extrema);
	extrema = get_extrema(fdf);
	x_transf_ratio = (float)WIDTH / extrema.x_max;
	y_transf_ratio = (float)HEIGTH / extrema.y_max;
	if (x_transf_ratio < y_transf_ratio)
		y_transf_ratio = (float)WIDTH / (float)HEIGTH * x_transf_ratio;
	else
		x_transf_ratio = (float)WIDTH / (float)HEIGTH * y_transf_ratio;
	while (ptr)
	{
		ptr->proj_data.x *= x_transf_ratio;
		ptr->proj_data.y *= y_transf_ratio;
		ptr = ptr->next;
	}
}

/*Resizes the projected map by strecthing x_values to make them fit the WIDTH
of the image. 'fdf->proj_data' is updated for each node of the list pointed at
by 'fdf'*/
void	resize_map(t_fdf **fdf)
{
	t_fdf		*ptr;
	t_extrema	extrema;
	float		x_transf_ratio;
	float		y_transf_ratio;

	ptr = *fdf;
	extrema = get_extrema(fdf);
	x_transf_ratio = (float)WIDTH / extrema.x_max;
	y_transf_ratio = (float)HEIGTH / (float)WIDTH * x_transf_ratio;
	while (ptr)
	{
		ptr->proj_data.x *= x_transf_ratio;
		ptr->proj_data.y *= y_transf_ratio;
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
