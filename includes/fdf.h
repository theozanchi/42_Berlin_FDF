/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:55:44 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/24 15:10:37 by tzanchi          ###   ########.fr       */
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

typedef struct s_3x3_matrix
{
	int	line_1[3];
	int	line_2[3];
	int	line_3[3];
}	t_3x3_matrix;

typedef struct s_3_vector
{
	int	x;
	int	y;
	int	z;
}	t_3_vector;

typedef struct s_fdf
{
	t_3_vector		data_3d;
	t_bool			end_of_line;
	struct s_fdf	*next;
}	t_fdf;

/*errors*/
t_bool	arg_is_valid(int argc, char **argv);
int		error(char *s);

/*file_parsing*/
t_exit	parse_line(char *line, t_fdf **fdf, int x_counter);
t_exit	parse_fdf_file(int fd, t_fdf **fdf);

/*free*/
void	free_char_array(char **s);
void	free_vectors(t_fdf **vectors);

/*main*/
int		main(int argc, char **argv);

/*utils_list*/
t_fdf	*ft_lstnew(int x, int y, int z, t_bool end_of_line);
void	ft_lstadd_back(t_fdf **lst, t_fdf *new);

#endif
