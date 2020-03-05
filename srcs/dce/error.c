/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:58:28 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/03 23:58:30 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		clos_e(void *param)
{
	(void)param;
	exit(0);
}

void	wrong_name(void)
{
	ft_putstr("wrong fractal name\ntype = mandelbrot, "
		"julia, mult_julia, mandelbar, burningship, celtic"
	", buffalo, perp_buffalo\n");
	exit(0);
}

void	error(int code)
{
	if (code)
	{
		ft_putnbr(code);
		ft_putstr("\n");
		ft_putstr("somthing gows wrong\n");
		exit(code);
	}
}
