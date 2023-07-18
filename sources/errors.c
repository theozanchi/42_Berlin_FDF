/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:53:21 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/18 15:15:08 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bool	arg_is_valid(int argc, char **argv)
{
	if (argc != 2)
		return (FALSE);
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".fdf"))
		return (FALSE);
	return (TRUE);
}

int	error(char *s)
{
	ft_printf("%s", s);
	return (1);
}
