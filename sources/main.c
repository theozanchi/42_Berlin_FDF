/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:53:00 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/10 13:35:10 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

int	main(int argc, char **argv)
{
	t_proj_data	data;

	if (!arg_is_valid(argc, argv))
		return (error(INVALID_ARG_ERR));
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd < 0)
		return (error(FILE_READING_ERR));
	if (!parse_fdf_file(data.fd, &data.fdf))
		return (error(MAP_PARSING_ERR));
	data.mlx = mlx_init(WIDTH, HEIGTH, ft_strrchr(argv[1], '/') + 1, TRUE);
	if (!data.mlx)
		return (error(MLX_INIT_ERR));
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGTH);
	if (!data.img || mlx_image_to_window(data.mlx, data.img, 0, 0) < 0)
		return (error(IMG_INIT_ERR));
	visualize_map(&data.fdf, data.img);
	mlx_key_hook(data.mlx, &my_keyhook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	free_vectors(&data.fdf);
	close(data.fd);
	return (0);
}
