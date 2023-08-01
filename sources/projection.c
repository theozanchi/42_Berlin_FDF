/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:42:25 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/01 14:55:41 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project_coordinates(t_fdf **fdf)
{
	t_fdf		*ptr;
	t_mtx_3x3	alp_mtx;
	t_mtx_3x3	bet_mtx;
	t_mtx_3x3	gam_mtx;

	ptr = *fdf;
	alp_mtx = alpha_rot_mtx(ft_rad(_ALPHA));
	bet_mtx = beta_rot_mtx(ft_rad(_BETA));
	gam_mtx = gamma_rot_mtx(ft_rad(_GAMMA));
	while (ptr)
	{
		ptr->proj_data = proj_vect(ptr->data, alp_mtx, bet_mtx, gam_mtx);
		ptr = ptr->next;
	}
}
