/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:46:41 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/14 15:20:34 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img(t_data *data)
{
	mlx_put_string(data->mlx, "Commands:", 5, 5);
	mlx_put_string(data->mlx, "ESC to close window", 5, 25);
	project_coordinates(&data->fdf);
	resize_map(&data->fdf);
	visualize_map(data);
}
