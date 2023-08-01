/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:55:44 by tzanchi           #+#    #+#             */
/*   Updated: 2023/08/01 18:15:23 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# define _ALPHA 35.264
# define _BETA 45
# define _GAMMA 0

# define WIDTH 1080
# define HEIGHT 607

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

typedef enum e_angle
{
	ALPHA,
	BETA,
	GAMMA
}	t_angle;

typedef struct s_mtx_3x3
{
	float	line_0[3];
	float	line_1[3];
	float	line_2[3];
}	t_mtx_3x3;

typedef struct s_vect_3
{
	float	x;
	float	y;
	float	z;
}	t_vect_3;

typedef struct s_fdf
{
	t_vect_3		data;
	t_vect_3		proj_data;
	t_bool			end_of_line;
	struct s_fdf	*next;
}	t_fdf;

/*_utils_list*/
t_fdf		*ft_lstnew(int x, int y, int z, t_bool end_of_line);
void		ft_lstadd_back(t_fdf **lst, t_fdf *new);
t_fdf		*get_nth_node(t_fdf *ptr, int n);

/*_utils_matrix_calc*/
t_vect_3	matrix_vector_mult(t_mtx_3x3 matrix, t_vect_3 vector);
t_mtx_3x3	alpha_rot_mtx(float theta);
t_mtx_3x3	beta_rot_mtx(float theta);
t_mtx_3x3	gamma_rot_mtx(float theta);
t_vect_3	proj_vect(t_vect_3 v, t_mtx_3x3 alp, t_mtx_3x3 bet, t_mtx_3x3 gam);

/*bresenham_line_algo*/
void		put_dot(mlx_image_t *img, int x, int y, uint32_t color, int thickness);
void		plot_line(t_vect_3 a, t_vect_3 b, mlx_image_t *img, int thickness, int colour);

/*errors*/
t_bool		arg_is_valid(int argc, char **argv);
int			error(char *s);

/*file_parsing*/
t_exit		parse_line(char *line, t_fdf **fdf, int x_counter);
t_exit		parse_fdf_file(int fd, t_fdf **fdf);

/*free*/
void		free_char_array(char **s);
void		free_vectors(t_fdf **vectors);

/*main*/
int			main(int argc, char **argv);

/*projection*/
void		project_coordinates(t_fdf **fdf);

/*visualize_map*/
int			get_line_length(t_fdf **fdf);
float		get_x_max(t_fdf **fdf);
void		resize_map(t_fdf **fdf);
void		visualize_map(t_fdf **fdf, mlx_image_t *img);

#endif
