/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils_list_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:17:03 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/16 17:10:12 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Creates a new t_fdf node with coordinates x, y, z and boolean flag for end of
line and returns a pointer to the newly created node*/
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

/*Adds a new node 'new' at the end of the t_fdf list pointed by 'lst'*/
void	ft_lstadd_back(t_data *data, t_fdf **lst_ptr, t_fdf *node)
{
	if (!data->fdf)
	{
		data->fdf = node;
		*lst_ptr = node;
	}
	else
	{
		(*lst_ptr)->next = node;
		*lst_ptr = node;
	}
}

/*Returns a pointer to the node located n elements after the node pointed at
by 'ptr'*/
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
