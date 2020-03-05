/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_celtic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:58:41 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/04 01:58:44 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	init_celtic(t_data params)
{
	params.arg.shift_x = 2.0;
	params.arg.shift_y = 2.0;
	params.fractal_type = "celtic";
	params = cl_krenal_creat(params, "srcs/fractol/celtic.cl");
	error(params.cl.ret);
	return (params);
}
