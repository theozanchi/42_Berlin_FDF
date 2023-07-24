/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:55:44 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/24 12:27:25 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# define ALPHA_ANGLE 35.264
# define BETA_ANGLE 45
# define GAMMA_ANGLE 0

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

typedef struct s_3d_vector
{
	int					x;
	int					y;
	int					z;
	t_bool				end_of_line;
	struct s_3d_vector	*next;
}	t_3d_vector;

/*errors*/
t_bool	arg_is_valid(int argc, char **argv);
int		error(char *s);

/*file_parsing*/
t_exit	parse_line(char *line, t_3d_vector **vectors, int x_counter);
t_exit	parse_fdf_file(int fd, t_3d_vector **vectors);

/*free*/
void	free_char_array(char **s);
void	free_vectors(t_3d_vector **vectors);

/*main*/
int		main(int argc, char **argv);

/*utils_list*/
t_3d_vector	*ft_lstnew(int x, int y, int z, t_bool end_of_line);
void	ft_lstadd_back(t_3d_vector **lst, t_3d_vector *new);

#endif
