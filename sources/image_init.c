/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:46:41 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/10 16:18:51 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img(t_proj_data *data)
{
	mlx_put_string(data->mlx, "Commands:", 5, 5);
	mlx_put_string(data->mlx, "ESC to close window", 5, 25);
}
