/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:00:06 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/04 00:00:08 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		mlx_inits(void)
{
	t_mlx	mlx_params;
	int		bit_depth;
	int		line;
	int		endian;

	bit_depth = 32;
	line = MAX_WIN_SIZE_X;
	endian = 0;
	mlx_params.mlx = mlx_init();
	mlx_params.wind = mlx_new_window(mlx_params.mlx, MAX_WIN_SIZE_X,\
	MAX_WIN_SIZE_Y, "fractol");
	if (!mlx_params.wind)
		error(-1);
	mlx_params.img = mlx_new_image(mlx_params.mlx, MAX_WIN_SIZE_X,\
	MAX_WIN_SIZE_Y);
	if (!mlx_params.img)
		error(-1);
	mlx_params.img_data = (int*)mlx_get_data_addr(mlx_params.img,\
	&bit_depth, &line, &endian);
	if (!mlx_params.img_data)
		error(-1);
	mlx_params.x_leng = MAX_WIN_SIZE_X;
	mlx_params.y_short = MAX_WIN_SIZE_Y;
	return (mlx_params);
}
