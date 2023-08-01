/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:37:59 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/01 18:13:15 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_dot(mlx_image_t *img, int x, int y, uint32_t color, int thickness)
{
	int	i;
	int	j;
	int	plot_x;
	int	plot_y;

	i = -thickness / 2;
	while (i <= thickness / 2)
	{
		j = -thickness / 2;
		while (j <= thickness / 2)
		{
			plot_x = x + i;
			plot_y = y + j;
			if (plot_x >= 0 && plot_x < WIDTH && plot_y >= 0 && plot_y < HEIGHT)
				mlx_put_pixel(img, plot_x, plot_y, color);
			j++;
		}
		i++;
	}
}

void	plot_line(t_vect_3 a, t_vect_3 b, mlx_image_t *img, int thickness, int colour)
{
	float	delta_x;
	float	delta_y;
	float	p;
	float	x;
	float	y;

	delta_x = fabs(b.x - a.x);
	delta_y = fabs(b.y - a.y);
	x = a.x;
	y = a.y;
	p = 2 * delta_y - delta_x;
	if (delta_y == 0)
	{
		while (x <= b.x)
		{
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
				put_dot(img, x, y, colour, thickness);
			x++;
		}
		return ;
	}
	while (x <= b.x)
	{
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			put_dot(img, x, y, colour, thickness);
		if (p >= 0)
		{
			y++;
			p += 2 * delta_y - 2 * delta_x;
		}
		else
			p += 2 * delta_y;
		x++;
	}
}
