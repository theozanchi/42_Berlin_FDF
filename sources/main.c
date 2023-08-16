/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:53:00 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/16 21:02:23 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

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
