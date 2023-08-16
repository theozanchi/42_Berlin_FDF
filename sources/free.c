/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:20:23 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/16 17:05:44 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Frees an array of strings*/
int	free_char_array(char **s)
{
	char	**ptr;

	if (!s || !*s)
		return (0);
	ptr = s;
	while (*ptr)
		free(*ptr++);
	free(s);
	return (0);
}

/*Frees and sets to NULL the linked list pointed at by 'fdf'*/
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
