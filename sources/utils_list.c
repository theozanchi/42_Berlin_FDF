/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:17:03 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/18 19:53:23 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_lstnew(int x, int y, int z, t_bool end_of_line)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->end_of_line = end_of_line;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	t_map	*ptr;

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
