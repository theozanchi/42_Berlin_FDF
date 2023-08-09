/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:37:59 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/09 13:39:50 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Initialize in the structure pointed at by 'ut' the initial values needed by
the Bresenham algorithm:
• (x0, y0) coordinates of the starting point
• (x1, y1) coordinates of the ending point
• delta_x: the absolute difference between x1 and x0
• delta_y: the absolute difference between y1 and y0
• is_steep: boolean indicating a steep line, based on delta_x and delta_y
• step_x: the direction in which to increase x in the algorithm
• step_y: the direction in which to increase y in the algorithm
• Call to the second part of the init function, init_bresenham_utils_2*/
void	init_bresenham_utils(t_br_utils *ut, t_vect_3 a, t_vect_3 b)
{
	ut->x0 = (int)a.x;
	ut->y0 = (int)a.y;
	ut->x1 = (int)b.x;
	ut->y1 = (int)b.y;
	ut->delta_x = abs(ut->x1 - ut->x0);
	ut->delta_y = abs(ut->y1 - ut->y0);
	ut->is_steep = (ut->delta_y > ut->delta_x);
	if (ut->x1 >= ut->x0)
		ut->step_x = 1;
	else
		ut->step_x = -1;
	if (ut->y1 >= ut->y0)
		ut->step_y = 1;
	else
		ut->step_y = -1;
	init_bresenham_utils_2(ut);
}

/*Initialize in the structure pointed at by 'ut' the initial values needed by
the Bresenham algorithm:
• if the line is steep, x0 and y0 are swapped, x1 and y1 are swapped
• if x0 > x1, x0 and x1 are swapped, y0 and y1 are swapped
• delta_x and delta_y are updated
• p: the error value is initialized*/
void	init_bresenham_utils_2(t_br_utils *ut)
{
	if (ut->is_steep)
	{
		ft_swap(&ut->x0, &ut->y0);
		ft_swap(&ut->x1, &ut->y1);
	}
	if (ut->x0 > ut->x1)
	{
		ft_swap(&ut->x0, &ut->x1);
		ft_swap(&ut->y0, &ut->y1);
	}
	ut->delta_x = ut->x1 - ut->x0;
	ut->delta_y = abs(ut->y1 - ut->y0);
	ut->p = 2 * ut->delta_y - ut->delta_x;
}

/*Draws a line in the image pointed at by 'img', with colour 'colour' from
starting point (a.x, a.y) to ending point (b.x, b.y)*/
void	plot(t_vect_3 a, t_vect_3 b, mlx_image_t *img, int colour)
{
	t_br_utils	ut;

	init_bresenham_utils(&ut, a, b);
	while (ut.x0 <= ut.x1)
	{
		if (ut.is_steep
			&& ut.y0 >= 0 && ut.y0 <= WIDTH && ut.x0 >= 0 && ut.x0 <= HEIGTH)
			mlx_put_pixel(img, ut.y0, ut.x0, colour);
		else
		{
			if (ut.x0 >= 0 && ut.x0 <= WIDTH && ut.y0 >= 0 && ut.y0 <= HEIGTH)
				mlx_put_pixel(img, ut.x0, ut.y0, colour);
		}
		if (ut.p >= 0)
		{
			ut.y0 += ut.step_y;
			ut.p -= 2 * ut.delta_x;
		}
		ut.p += 2 * ut.delta_y;
		ut.x0++;
	}
}
