/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:43:29 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/15 20:17:46 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_RIGHT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		shift_map(data, 1, 0);
		ft_memset(data->img->pixels, 0x00000000,
			data->img->width * data->img->height * sizeof(int32_t));
		visualize_map(data);
	}
	if (keydata.key == MLX_KEY_LEFT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		shift_map(data, -1, 0);
		ft_memset(data->img->pixels, 0x00000000,
			data->img->width * data->img->height * sizeof(int32_t));
		visualize_map(data);
	}
	if (keydata.key == MLX_KEY_UP
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		shift_map(data, 0, -1);
		ft_memset(data->img->pixels, 0x00000000,
			data->img->width * data->img->height * sizeof(int32_t));
		visualize_map(data);
	}
	if (keydata.key == MLX_KEY_DOWN
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		shift_map(data, 0, 1);
		ft_memset(data->img->pixels, 0x00000000,
			data->img->width * data->img->height * sizeof(int32_t));
		visualize_map(data);
	}
	if ((keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		&& (keydata.key == MLX_KEY_X || keydata.action == MLX_PRESS))
	{
		data->alpha++;
		project_coordinates(data);
		ft_memset(data->img->pixels, 0x00000000,
			data->img->width * data->img->height * sizeof(int32_t));
		visualize_map(data);
	}
}
