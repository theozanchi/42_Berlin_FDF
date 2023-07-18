/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:20:23 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/18 17:41:22 by tzanchi          ###   ########.fr       */
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

void	free_map(t_map **map)
{
	t_map	*current;
	t_map	*next;

	if (!map || !*map)
		return ;
	current = *map;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*map = NULL;
}
