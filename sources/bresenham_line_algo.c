/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:37:59 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/26 18:33:14 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_line(t_vect_3 a, t_vect_3 b, mlx_image_t *img)
{
	int	delta_x;
	int	delta_y;
	int	p;
	int	x;
	int	y;

	delta_x = b.x - a.x;
	delta_y = b.y - a.y;
	x = a.x;
	y = a.y;
	p = 2 * delta_y - delta_x;
	while (x < b.x)
	{
		if (x > 0 && x <= HEIGHT && y > 0 && y <= WIDTH)
			mlx_put_pixel(img, x, y, 255);
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
