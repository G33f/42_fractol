/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:59:05 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/03 23:59:08 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	init_julia(t_data params)
{
	params.arg.shift_x = 0.7;
	params.arg.shift_y = 2.0;
	params.fractal_type = "julia";
	params = cl_krenal_creat(params, "srcs/fractol/drow_julia.cl");
	error(params.cl.ret);
	return (params);
}
