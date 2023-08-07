/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:11:34 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/07 15:49:24 by tzanchi          ###   ########.fr       */
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
	if (extrema->x_min >= 0 && extrema->y_min >= 0)
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

/*Puts the whole map into the frame by switching negative x and y values. Then
resizes the projected map by applying the minimal transformation ratio on the x
and y axis for each node of the list pointed at by 'fdf'*/
void	resize_map(t_fdf **fdf)
{
	t_fdf		*ptr;
	t_extrema	extr;
	float		ratio;

	ptr = *fdf;
	extr = get_extrema(fdf);
	move_map_to_frame(fdf, &extr);
	extr = get_extrema(fdf);
	ratio = ft_min_float((float)WIDTH / extr.x_max, (float)HEIGTH / extr.y_max);
	while (ptr)
	{
		ptr->proj_data.x *= ratio;
		ptr->proj_data.y *= ratio;
		ptr = ptr->next;
	}
}

void	put_cross(t_vect_3 v, mlx_image_t *img, int colour)
{
	if ((int)v.x >= 0 && (int)v.x <= WIDTH
		&& (int)v.y >= 0 && (int)v.y <= HEIGTH)
		mlx_put_pixel(img, (int)v.x, (int)v.y, colour);
	if ((int)v.x >= 1 && (int)v.x <= WIDTH + 1
		&& (int)v.y >= 0 && (int)v.y <= HEIGTH)
		mlx_put_pixel(img, (int)v.x - 1, (int)v.y, colour);
	if ((int)v.x >= -1 && (int)v.x <= WIDTH - 1
		&& (int)v.y >= 0 && (int)v.y <= HEIGTH)
		mlx_put_pixel(img, (int)v.x + 1, (int)v.y, colour);
	if ((int)v.x >= 0 && (int)v.x <= WIDTH
		&& (int)v.y >= 1 && (int)v.y <= HEIGTH + 1)
		mlx_put_pixel(img, (int)v.x, (int)v.y - 1, colour);
	if ((int)v.x >= 0 && (int)v.x <= WIDTH
		&& (int)v.y >= -1 && (int)v.y <= HEIGTH - 1)
		mlx_put_pixel(img, (int)v.x, (int)v.y + 1, colour);
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
		put_cross(ptr->proj_data, img, 0x000000FF);
		ptr = ptr->next;
	}
}
