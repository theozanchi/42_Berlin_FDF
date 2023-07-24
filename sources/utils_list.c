/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:17:03 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/24 15:02:10 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*ft_lstnew(int x, int y, int z, t_bool end_of_line)
{
	t_fdf	*new;

	new = malloc(sizeof(t_fdf));
	if (new == NULL)
		return (NULL);
	new->data_3d.x = x;
	new->data_3d.y = y;
	new->data_3d.z = z;
	new->end_of_line = end_of_line;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_fdf **lst, t_fdf *new)
{
	t_fdf	*ptr;

	if (!*lst)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
