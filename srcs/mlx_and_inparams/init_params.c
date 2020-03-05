/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:59:56 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/03 23:59:59 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_check(t_data *p, char *set)
{
	if (ft_strcmp(set, "mandelbrot") == 0)
		*p = init_mandelbrot(*p);
	else if (ft_strcmp(set, "julia") == 0)
		*p = init_julia(*p);
	else if (ft_strcmp(set, "mult_julia") == 0)
	{
		p->arg.is_locked = 1;
		*p = init_julia(*p);
	}
	else if (ft_strcmp(set, "mandelbar") == 0)
		*p = init_mandelbar(*p);
	else if (ft_strcmp(set, "burningship") == 0)
		*p = init_burningship(*p);
	else if (ft_strcmp(set, "celtic") == 0)
		*p = init_celtic(*p);
	else if (ft_strcmp(set, "buffalo") == 0)
		*p = init_buffalo(*p);
	else if (ft_strcmp(set, "perp_buffalo") == 0)
		*p = init_perp_buffalo(*p);
	else
		wrong_name();
	*p = cl_buffer(*p);
}

t_data		init_params(char *set)
{
	t_data p;

	p.arg.zoom = 250;
	p.arg.iterations = MAX_ITERATION;
	p.arg.c_x = -0.4;
	p.arg.c_y = 0.6;
	p.arg.is_locked = 0;
	p.arg.color = 0.2;
	p.arg.lok = 1;
	p.cl = cl_init();
	p.mlx = mlx_inits();
	set_check(&p, set);
	return (p);
}
