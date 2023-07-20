/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:53:00 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/20 10:29:41 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_3d_vector	*vectors;

	if (!arg_is_valid(argc, argv))
		return (error(INVALID_ARG_ERR));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error(FILE_READING_ERR));
	if (!parse_fdf_file(fd, &vectors))
		return (error(MAP_PARSING_ERR));
	free_vectors(&vectors);
	close(fd);
	return (0);
}
