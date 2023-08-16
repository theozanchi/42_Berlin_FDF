/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:43:29 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/16 21:33:12 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_angle(float *angle, float increment)
{
	*angle += increment;
	if (*angle > 360)
		*angle -= 360;
	if (*angle < 0)
		*angle = 360 - *angle;
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_RIGHT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		shift_map(data, 1, 0);
	if (keydata.key == MLX_KEY_LEFT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		shift_map(data, -1, 0);
	if (keydata.key == MLX_KEY_UP
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		shift_map(data, 0, -1);
	if (keydata.key == MLX_KEY_DOWN
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		shift_map(data, 0, 1);
}
