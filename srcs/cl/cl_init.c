/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:57:15 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/03 23:57:17 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cl	cl_init(void)
{
	t_cl	cl;

	cl.ret = clGetPlatformIDs(2, &cl.pid, &cl.ret_num_p);
	error(cl.ret);
	cl.ret = clGetDeviceIDs(cl.pid, CL_DEVICE_TYPE_GPU, 1,
			&cl.did, &cl.ret_num_d);
	error(cl.ret);
	cl.context = clCreateContext(NULL, 1, &cl.did, NULL, NULL, &cl.ret);
	error(cl.ret);
	cl.c_cueue = clCreateCommandQueue(cl.context, cl.did, 0, &cl.ret);
	error(cl.ret);
	return (cl);
}
