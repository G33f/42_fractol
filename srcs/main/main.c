/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:59:43 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/03 23:59:45 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	params;

	if (argc != 2)
		exit(0);
	params = init_params(argv[1]);
	draw(params);
	mlx_clear_window(params.mlx.mlx, params.mlx.wind);
	mlx_put_image_to_window(params.mlx.mlx,\
	params.mlx.wind, params.mlx.img, 0, 0);
	mlx_hook(params.mlx.wind, 2, 0, kay1, &params);
	mlx_hook(params.mlx.wind, 3, 0, kay2, &params);
	mlx_hook(params.mlx.wind, 4, 0, mouse_press, &params);
	mlx_hook(params.mlx.wind, 17, 0, clos_e, &params);
	mlx_hook(params.mlx.wind, 6, 0, mouse_move, &params);
	mlx_loop_hook(params.mlx.mlx, cikle, &params);
	mlx_loop(params.mlx.mlx);
	clReleaseMemObject(params.cl.mobj);
	return (0);
}
