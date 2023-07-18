/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:55:44 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/18 20:21:03 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_exit
{
	FAILURE,
	SUCCESS
}	t_exit;

typedef struct s_map
{
	int				x;
	int				y;
	int				z;
	t_bool			end_of_line;
	struct s_map	*next;
}	t_map;

/*errors*/
t_bool	arg_is_valid(int argc, char **argv);
int		error(char *s);

/*free*/
void	free_char_array(char **s);
void	free_map(t_map **map);

/*main*/
int		main(int argc, char **argv);

/*map_parsing*/
t_exit	parse_line(char *line, t_map **map, int x_counter);
t_exit	parse_map(int fd, t_map **map);

/*utils_list*/
t_map	*ft_lstnew(int x, int y, int z, t_bool end_of_line);
void	ft_lstadd_back(t_map **lst, t_map *new);

#endif
