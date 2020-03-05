/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:58:18 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/03 23:58:21 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_data p)
{
	int		mem_len;
	size_t	global_work_size;

	mem_len = MAX_WIN_SIZE_X * MAX_WIN_SIZE_Y;
	global_work_size = MAX_WIN_SIZE_X * MAX_WIN_SIZE_Y;
	cl_set_args(p);
	p.cl.ret = clEnqueueNDRangeKernel(p.cl.c_cueue, p.cl.kernal, 1,\
			NULL, &global_work_size, NULL, 0, NULL, NULL);
	error(p.cl.ret);
	p.cl.ret = clEnqueueReadBuffer(p.cl.c_cueue, p.cl.mobj,\
			CL_TRUE, 0, mem_len * sizeof(int), p.mlx.img_data, 0, NULL, NULL);
	error(p.cl.ret);
	mlx_put_image_to_window(p.mlx.mlx,\
			p.mlx.wind, p.mlx.img, 0, 0);
}
