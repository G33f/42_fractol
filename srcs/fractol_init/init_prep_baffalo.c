/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prep_baffalo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 02:32:05 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/04 02:32:07 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	init_perp_buffalo(t_data params)
{
	params.arg.shift_x = 2.0;
	params.arg.shift_y = 2.0;
	params.fractal_type = "perp_buffalo";
	params = cl_krenal_creat(params, "srcs/fractol/perp_baffalo.cl");
	error(params.cl.ret);
	return (params);
}
