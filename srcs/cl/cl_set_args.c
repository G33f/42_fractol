/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:57:47 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/03 23:57:51 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	cl_set_julia_args(t_data p)
{
	p.cl.ret = clSetKernelArg(p.cl.kernal, 8, sizeof(p.arg.c_x), &p.arg.c_x);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernal, 9, sizeof(p.arg.c_y), &p.arg.c_y);
	error(p.cl.ret);
}

void		cl_set_args(t_data p)
{
	p.cl.ret = clSetKernelArg(p.cl.kernal, 1, sizeof(int), &p.mlx.x_leng);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernal, 2, sizeof(int), &p.mlx.y_short);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernal, 3, sizeof(int), &p.arg.iterations);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernal, 4, sizeof(p.arg.zoom), \
	&p.arg.zoom);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernal, 5, sizeof(p.arg.shift_x), \
	&p.arg.shift_x);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernal, 6, sizeof(p.arg.shift_y), \
	&p.arg.shift_y);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernal, 7, sizeof(p.arg.color), \
	&p.arg.color);
	error(p.cl.ret);
	if (ft_strcmp(p.fractal_type, "julia") == 0)
		cl_set_julia_args(p);
}
