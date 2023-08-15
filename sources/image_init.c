/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:46:41 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/15 20:19:46 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img(t_data *data)
{
	t_fdf	*ptr;

	mlx_put_string(data->mlx, "Commands:", 5, 5);
	mlx_put_string(data->mlx, "ESC to close window", 5, 25);
	mlx_put_string(data->mlx, "Move image with keyboard arrows", 5, 45);
	data->alpha = _ALPHA;
	data->beta = _BETA;
	data->gamma = _GAMMA;
	ptr = data->fdf;
	while (ptr)
	{
		ptr->proj_data = ptr->data;
		ptr = ptr->next;
	}
	project_coordinates(data);
	resize_map(&data->fdf);
	visualize_map(data);
}
