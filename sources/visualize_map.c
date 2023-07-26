/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:11:34 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/26 11:00:18 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	visualize_map(t_fdf **fdf, mlx_image_t *img)
{
	t_fdf	*ptr;

	ptr = *fdf;
	while (!ptr->end_of_line)
	{
		plot_line(ptr->proj_data, ptr->next->proj_data, img);
		ptr = ptr->next;
	}
}
