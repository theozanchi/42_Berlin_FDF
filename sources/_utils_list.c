/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:17:03 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/01 17:11:15 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*ft_lstnew(int x, int y, int z, t_bool end_of_line)
{
	t_fdf	*new;

	new = malloc(sizeof(t_fdf));
	if (new == NULL)
		return (NULL);
	new->data.x = x;
	new->data.y = y;
	new->data.z = z;
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

t_fdf	*get_nth_node(t_fdf *ptr, int n)
{
	t_fdf	*node;

	node = ptr;
	while (n--)
	{
		if (!node->next)
			return (NULL);
		node = node->next;
	}
	return (node);
}
