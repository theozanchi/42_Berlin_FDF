/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:20:23 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/20 10:27:34 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_char_array(char **s)
{
	char	**ptr;

	if (!s || !*s)
		return ;
	ptr = s;
	while (*ptr)
		free(*ptr++);
	free(s);
}

void	free_vectors(t_3d_vector **vectors)
{
	t_3d_vector	*current;
	t_3d_vector	*next;

	if (!vectors || !*vectors)
		return ;
	current = *vectors;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*vectors = NULL;
}
