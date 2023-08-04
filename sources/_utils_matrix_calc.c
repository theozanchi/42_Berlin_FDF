/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils_matrix_calc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:17:00 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/04 15:09:14 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

/*Generates and returns the 3x3 rotation matrix of an angle 'theta' (in radian)
around the x axis*/
t_mtx_3x3	alpha_rot_mtx(float theta)
{
	t_mtx_3x3	mtx;

	mtx.line_0[0] = 1;
	mtx.line_0[1] = 0;
	mtx.line_0[2] = 0;
	mtx.line_1[0] = 0;
	mtx.line_1[1] = cos(theta);
	mtx.line_1[2] = -sin(theta);
	mtx.line_2[0] = 0;
	mtx.line_2[1] = sin(theta);
	mtx.line_2[2] = cos(theta);
	return (mtx);
}

/*Generates and returns the 3x3 rotation matrix of an angle 'theta' (in radian)
around the y axis*/
t_mtx_3x3	beta_rot_mtx(float theta)
{
	t_mtx_3x3	mtx;

	mtx.line_0[0] = cos(theta);
	mtx.line_0[1] = 0;
	mtx.line_0[2] = sin(theta);
	mtx.line_1[0] = 0;
	mtx.line_1[1] = 1;
	mtx.line_1[2] = 0;
	mtx.line_2[0] = -sin(theta);
	mtx.line_2[1] = 0;
	mtx.line_2[2] = cos(theta);
	return (mtx);
}

/*Generates and returns the 3x3 rotation matrix of an angle 'theta' (in radian)
around the z axis*/
t_mtx_3x3	gamma_rot_mtx(float theta)
{
	t_mtx_3x3	mtx;

	mtx.line_0[0] = cos(theta);
	mtx.line_0[1] = -sin(theta);
	mtx.line_0[2] = 0;
	mtx.line_1[0] = sin(theta);
	mtx.line_1[1] = cos(theta);
	mtx.line_1[2] = 0;
	mtx.line_2[0] = 0;
	mtx.line_2[1] = 0;
	mtx.line_2[2] = 1;
	return (mtx);
}

/*Returns the projected vector 'v' after a rotation of:
• 'alp' radian around the x axis
• 'bet radian around the y axis
• 'gam' radian around the z axis*/
t_vect_3	proj_vect(t_vect_3 v, t_mtx_3x3 alp, t_mtx_3x3 bet, t_mtx_3x3 gam)
{
	t_vect_3	proj_vect;

	proj_vect = matrix_vector_mult(alp, v);
	proj_vect = matrix_vector_mult(bet, proj_vect);
	proj_vect = matrix_vector_mult(gam, proj_vect);
	return (proj_vect);
}
