/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_kernal_creat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:57:26 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/03 23:57:29 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	cl_krenal_creat(t_data p, char *f_name)
{
	size_t	src_size;
	size_t	log_size;
	char	*src;
	char	*log;

	src_size = read_cl_src(&src, f_name);
	p.cl.program = clCreateProgramWithSource(p.cl.context, 1,
			(const char **)&src, (const size_t *)&src_size, &p.cl.ret);
	error(p.cl.ret);
	p.cl.ret = clBuildProgram(p.cl.program, 1, &p.cl.did, NULL, NULL, NULL);
	error(p.cl.ret);
	clGetProgramBuildInfo(p.cl.program, p.cl.did, CL_PROGRAM_BUILD_LOG,
			0, NULL, &log_size);
	if (!(log = malloc(sizeof(char) * log_size)))
		error(1);
	clGetProgramBuildInfo(p.cl.program, p.cl.did, CL_PROGRAM_BUILD_LOG,
			log_size, log, NULL);
	ft_putstr(log);
	error(p.cl.ret);
	p.cl.kernal = clCreateKernel(p.cl.program,\
			"draw", &p.cl.ret);
	error(p.cl.ret);
	free(src);
	free(log);
	return (p);
}
