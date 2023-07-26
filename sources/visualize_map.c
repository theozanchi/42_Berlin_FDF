/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:11:34 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/26 17:07:21 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	visualize_map(t_fdf **fdf, mlx_image_t *img)
{
	t_fdf	*ptr;
	t_fdf	*next_line_start;

	ptr = *fdf;
	next_line_start = ptr;
	while (ptr)
	{
		while (ptr && !ptr->end_of_line)
		{
			plot_line(ptr->proj_data, ptr->next->proj_data, img);
			ptr = ptr->next;
		}
		if (next_line_start)
		{
			while (next_line_start && next_line_start->end_of_line)
				next_line_start = next_line_start->next;
			ptr = next_line_start;
			if (ptr)
				next_line_start = ptr->next;
		}
	}
}
