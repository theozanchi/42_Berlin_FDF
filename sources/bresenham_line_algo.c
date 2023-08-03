/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:37:59 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/03 13:09:18 by tzanchi          ###   ########.fr       */
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
			if (plot_x >= 0 && plot_x <= WIDTH
				&& plot_y >= 0 && plot_y <= HEIGTH)
				mlx_put_pixel(img, plot_x, plot_y, color);
			j++;
		}
		i++;
	}
}

void	init_bresenham_utils(t_br_utils *ut, t_vect_3 a, t_vect_3 b)
{
	ut->delta_x = fabs(b.x - a.x);
	ut->delta_y = fabs(b.y - a.y);
	ut->p = 2 * ut->delta_y - ut->delta_x;
	if (b.x >= a.x)
		ut->step_x = 1;
	else
		ut->step_x = -1;
	if (b.y >= a.y)
		ut->step_y = 1;
	else
		ut->step_y = -1;
	ut->x0 = a.x;
	ut->y0 = a.y;
	ut->x1 = b.x;
	ut->y1 = b.y;
}

void	horizontal(t_br_utils ut, mlx_image_t *img, int thick, int colour)
{
	while (ut.x0 != ut.x1)
	{
		if (ut.x0 >= 0 && ut.x0 <= WIDTH && ut.y0 >= 0 && ut.y0 <= HEIGTH)
			put_dot(img, (int)ut.x0, (int)ut.y0, colour, thick);
		ut.x0 += ut.step_x;
	}
}

void	vertical(t_br_utils ut, mlx_image_t *img, int thick, int colour)
{
	while (ut.y0 != ut.y1)
	{
		if (ut.x0 >= 0 && ut.x0 <= WIDTH && ut.y0 >= 0 && ut.y0 <= HEIGTH)
			put_dot(img, (int)ut.x0, (int)ut.y0, colour, thick);
		ut.y0 += ut.step_y;
	}
}

void	plot(t_vect_3 a, t_vect_3 b, mlx_image_t *img, int thick, int colour)
{
	t_br_utils	ut;

	init_bresenham_utils(&ut, a, b);
	if (ut.delta_y == 0)
		horizontal(ut, img, thick, colour);
	else if (ut.delta_x == 0)
		vertical(ut, img, thick, colour);
	else
	{
		while (ut.x0 != ut.x1)
		{
			if (ut.x0 >= 0 && ut.x0 < WIDTH && ut.y0 >= 0 && ut.y0 <= HEIGTH)
				put_dot(img, (int)ut.x0, (int)ut.y0, colour, thick);
			if (ut.p >= 0)
			{
				ut.y0 += ut.step_y;
				ut.p += 2 * ut.delta_y - 2 * ut.delta_x;
			}
			else
				ut.p += 2 * ut.delta_y;
			ut.x0 += ut.step_x;
		}
	}
}
