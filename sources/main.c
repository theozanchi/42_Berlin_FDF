/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:53:00 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/16 21:45:31 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

t_exit	init_img(t_data *data)
{
	t_fdf	*ptr;

	data->img = mlx_new_image(data->mlx,
			data->mlx->width, data->mlx->height - 20);
	if (!data->img || mlx_image_to_window(data->mlx, data->img, 10, 10) < 0)
		return (FAILURE);
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
	return (SUCCESS);
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (!arg_is_valid(argc, argv))
		return (error(INVALID_ARG_ERR));
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd < 0)
		return (error(FILE_READING_ERR));
	if (!parse_fdf_file(&data))
		return (error(MAP_PARSING_ERR));
	data.mlx = mlx_init(WIDTH, HEIGTH, ft_strrchr(argv[1], '/') + 1, TRUE);
	if (!data.mlx)
		return (error(MLX_INIT_ERR));
	if (!init_img(&data))
		return (error(IMG_INIT_ERR));
	mlx_key_hook(data.mlx, &my_keyhook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	free_vectors(&data.fdf);
	close(data.fd);
	return (0);
}
