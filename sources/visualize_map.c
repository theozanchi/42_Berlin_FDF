/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:11:34 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/16 17:12:30 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_map(t_data *data, int x, int y)
{
	t_fdf	*ptr;

	ptr = data->fdf;
	while (ptr)
	{
		ptr->proj_data.x += x;
		ptr->proj_data.y += y;
		ptr = ptr->next;
	}
	ft_memset(data->img->pixels, 0x00000000,
		data->img->width * data->img->height * sizeof(int32_t));
	visualize_map(data);
}

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

/*Loops through the list pointed at by 'fdf' and connects all nodes to the
surrounding nodes (top, down, left and right)*/
void	visualize_map(t_data *data)
{
	t_fdf	*ptr;
	int		line_len;

	ptr = data->fdf;
	line_len = get_line_length(&data->fdf);
	while (ptr)
	{
		if (!ptr->end_of_line)
			plot(ptr->proj_data, ptr->next->proj_data, data->img, ptr->colour);
		if (!is_last_line(ptr, line_len))
			plot(ptr->proj_data, get_nth_node(ptr, line_len)->proj_data,
				data->img, ptr->colour);
		ptr = ptr->next;
	}
}
