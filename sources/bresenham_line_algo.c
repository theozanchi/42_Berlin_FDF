/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:37:59 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/08 15:16:32 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Initialize in the structure pointed at by 'ut' the initial values needed by
the Bresenham algorithm:
• (x0, y0) coordinates of the starting point
• (x1, y1) coordinates of the ending point
• delta_x: the absolute difference between x1 and x0
• delta_y: the absolute difference between y1 and y0
• p: the error value
• step_x: the direction in which to increase x in the algorithm
• step_y: the direction in which to increase y in the algorithm*/
void	init_bresenham_utils(t_br_utils *ut, t_vect_3 a, t_vect_3 b)
{
	ut->x0 = a.x;
	ut->y0 = a.y;
	ut->x1 = b.x;
	ut->y1 = b.y;
	ut->delta_x = abs(ut->x1 - ut->x0);
	ut->delta_y = abs(ut->y1 - ut->y0);
	ut->p = 2 * ut->delta_y - ut->delta_x;
	if (ut->x1 >= ut->x0)
		ut->step_x = 1;
	else
		ut->step_x = -1;
	if (ut->y1 >= ut->y0)
		ut->step_y = 1;
	else
		ut->step_y = -1;
}

/*Draws a horizontal line in the image pointed at by 'img', with colour 'colour'
and at heigth 'ut->y0'*/
void	horizontal(t_br_utils ut, mlx_image_t *img, int colour)
{
	while (ut.x0 != ut.x1)
	{
		if (ut.x0 >= 0 && ut.x0 <= WIDTH && ut.y0 >= 0 && ut.y0 <= HEIGTH)
			mlx_put_pixel(img, ut.x0, ut.y0, colour);
		ut.x0 += ut.step_x;
	}
}

/*Draws a vertical line in the image pointed at by 'img', with colour 'colour'
and at distance 'ut->x0'*/
void	vertical(t_br_utils ut, mlx_image_t *img, int colour)
{
	while (ut.y0 != ut.y1)
	{
		if (ut.x0 >= 0 && ut.x0 <= WIDTH && ut.y0 >= 0 && ut.y0 <= HEIGTH)
			mlx_put_pixel(img, ut.x0, ut.y0, colour);
		ut.y0 += ut.step_y;
	}
}

/*Draws a line in the image pointed at by 'img', with colour 'colour' from
starting point (a.x, a.y) to ending point (b.x, b.y)*/
void	plot(t_vect_3 a, t_vect_3 b, mlx_image_t *img, int colour)
{
	t_br_utils	ut;

	init_bresenham_utils(&ut, a, b);
	if (ut.delta_x == 0 && ut.delta_y == 0)
		mlx_put_pixel(img, ut.x0, ut.y0, colour);
	else if (ut.delta_y == 0)
		horizontal(ut, img, colour);
	else if (ut.delta_x == 0)
		vertical(ut, img, colour);
	else
	{
		while (ut.x0 != ut.x1)
		{
			if (ut.x0 >= 0 && ut.x0 <= WIDTH && ut.y0 >= 0 && ut.y0 <= HEIGTH)
				mlx_put_pixel(img, ut.x0, ut.y0, colour);
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
