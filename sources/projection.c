/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:42:25 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/15 20:18:27 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Projects the coordinates of all vectors in the list pointed at by 'fdf' by
rotating the map of an angle:
• _ALPHA (in degrees) around the x axis
• _BETA (in degrees) around the y axis
• _GAMMA (in degrees) around the z axis*/
void	project_coordinates(t_data *data)
{
	t_fdf		*ptr;
	t_mtx_3x3	mtx;

	ptr = data->fdf;
	mtx = rot_mtx(ft_rad(data->alpha), ft_rad(data->beta), ft_rad(data->gamma));
	while (ptr)
	{
		ptr->proj_data = matrix_vector_mult(mtx, ptr->proj_data);
		ptr = ptr->next;
	}
}

/*Returns as a 1x3 vector the result of the multiplication of the 3x3 matrix
'matrix' by the 1x3 vector 'vector'*/
t_vect_3	matrix_vector_mult(t_mtx_3x3 matrix, t_vect_3 vector)
{
	t_vect_3	result;

	result.x = matrix.line_0[0] * vector.x
		+ matrix.line_0[1] * vector.y
		+ matrix.line_0[2] * vector.z;
	result.y = matrix.line_1[0] * vector.x
		+ matrix.line_1[1] * vector.y
		+ matrix.line_1[2] * vector.z;
	result.z = matrix.line_2[0] * vector.x
		+ matrix.line_2[1] * vector.y
		+ matrix.line_2[2] * vector.z;
	return (result);
}

/*Generates and returns the 3x3 rotation matrix of an angle
• 'alp' (in radian) around the x axis
• 'bet' (in radian) around the y axis
• 'gam' (in radian) around the z axis*/
t_mtx_3x3	rot_mtx(float alp, float bet, float gam)
{
	t_mtx_3x3	mtx;

	mtx.line_0[0] = cos(bet) * cos(gam);
	mtx.line_0[1] = sin(alp) * sin(bet) * cos(gam) - cos(alp) * sin(gam);
	mtx.line_0[2] = cos(alp) * sin(bet) * cos(gam) + sin(alp) * sin(gam);
	mtx.line_1[0] = cos(bet) * sin(gam);
	mtx.line_1[1] = sin(alp) * sin(bet) * sin(gam) + cos(alp) * cos(gam);
	mtx.line_1[2] = cos(alp) * sin(bet) * sin(gam) - sin(alp) * cos(gam);
	mtx.line_2[0] = -sin(bet);
	mtx.line_2[1] = sin(alp) * cos(bet);
	mtx.line_2[2] = cos(alp) * cos(bet);
	return (mtx);
}
