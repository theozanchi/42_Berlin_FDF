/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:53:00 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/03 13:10:20 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_fdf		*fdf;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (!arg_is_valid(argc, argv))
		return (error(INVALID_ARG_ERR));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error(FILE_READING_ERR));
	if (!parse_fdf_file(fd, &fdf))
		return (error(MAP_PARSING_ERR));
	mlx = mlx_init(WIDTH, HEIGTH, argv[1], TRUE);
	if (!mlx)
		return (error(MLX_INIT_ERR));
	img = mlx_new_image(mlx, WIDTH, HEIGTH);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		return (error(IMG_INIT_ERR));
	project_coordinates(&fdf);
	resize_map(&fdf);
	visualize_map(&fdf, img);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_vectors(&fdf);
	close(fd);
	return (0);
}
