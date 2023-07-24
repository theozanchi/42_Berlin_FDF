/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:20:23 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/24 15:03:30 by tzanchi          ###   ########.fr       */
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

void	free_vectors(t_fdf **fdf)
{
	t_fdf	*current;
	t_fdf	*next;

	if (!fdf || !*fdf)
		return ;
	current = *fdf;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*fdf = NULL;
}
