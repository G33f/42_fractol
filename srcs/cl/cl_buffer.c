/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:56:59 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/03 23:57:03 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	cl_buffer(t_data p)
{
	int		mem_len;

	mem_len = MAX_WIN_SIZE_X * MAX_WIN_SIZE_Y;
	p.cl.mobj = clCreateBuffer(p.cl.context, CL_MEM_READ_WRITE,\
			mem_len * sizeof(cl_int), NULL, &p.cl.ret);
	error(p.cl.ret);
	p.cl.ret = clEnqueueWriteBuffer(p.cl.c_cueue, p.cl.mobj, CL_TRUE,\
			0, mem_len * sizeof(cl_int), p.mlx.img_data, 0, NULL, NULL);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernal, 0,\
			sizeof(cl_mem), (void *)&p.cl.mobj);
	error(p.cl.ret);
	return (p);
}
