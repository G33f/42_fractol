/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 02:37:01 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/04 02:37:04 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_WIN_SIZE_X 1000
# define MAX_WIN_SIZE_Y 1000
# define MAX_ITERATION 100

# include <OpenCL/cl.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "libft.h"

typedef struct			s_cl
{
	cl_int				ret;
	cl_platform_id		pid;
	cl_uint				ret_num_p;
	cl_device_id		did;
	cl_uint				ret_num_d;
	cl_context			context;
	cl_command_queue	c_cueue;
	cl_program			program;
	cl_kernel			kernal;
	cl_mem				mobj;
}						t_cl;

typedef struct			s_mlx
{
	void				*mlx;
	void				*wind;
	void				*img;
	int					*img_data;
	unsigned int		x_leng;
	unsigned int		y_short;
}						t_mlx;

typedef	struct			s_args
{
	double				zoom;
	double				shift_x;
	double				shift_y;
	double				c_x;
	double				c_y;
	int					iterations;
	char				is_locked;
	int					lok;
	double				color;
	int					ckl;
}						t_args;

typedef struct			s_mouse
{
	int					x;
	int					y;
}						t_mouse;

typedef struct			s_data
{
	t_cl				cl;
	t_mlx				mlx;
	t_args				arg;
	t_mouse				mous;
	char				*fractal_type;
}						t_data;

t_data					init_params(char *set);

t_cl					cl_init(void);
t_data					cl_krenal_creat(t_data p, char *f_name);
t_data					cl_buffer(t_data p);
void					cl_set_args(t_data p);
size_t					read_cl_src(char **src, char *file_name);

t_mlx					mlx_inits(void);

void					draw(t_data p);

void					error(int code);
void					wrong_name(void);

t_data					init_mandelbrot(t_data params);
t_data					init_julia(t_data params);
t_data					init_mandelbar(t_data params);
t_data					init_burningship(t_data params);
t_data					init_celtic(t_data params);
t_data					init_buffalo(t_data params);
t_data					init_perp_buffalo(t_data params);

int						kay1(int key, t_data *p);
int						kay2(int key, t_data *p);
int						cikle(t_data *p);
int						mouse_press(int kay, int x, int y, t_data *p);
int						mouse_move(int x, int y, t_data *p);
int						clos_e(void *param);

#endif
