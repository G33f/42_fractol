/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:44:34 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/03 23:58:12 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_data *p)
{
	if (!(p->mous.x) && !(p->mous.y))
	{
		p->mous.x = x;
		p->mous.y = y;
	}
	if (p->arg.is_locked)
	{
		p->arg.c_x += (x - p->mous.x) / p->arg.zoom;
		p->arg.c_y += (y - p->mous.y) / p->arg.zoom;
		p->mous.x = x;
		p->mous.y = y;
		draw(*p);
	}
	return (0);
}

int	mouse_press(int kay, int x, int y, t_data *p)
{
	double a[2];
	double a1;
	double b1;

	a[0] = x / p->arg.zoom + p->arg.shift_x;
	a[1] = y / p->arg.zoom + p->arg.shift_y;
	if (kay == 4)
	{
		a1 = x / (p->arg.zoom * 1.1) + p->arg.shift_x;
		b1 = y / (p->arg.zoom * 1.1) + p->arg.shift_y;
		p->arg.shift_x += a1 - a[0];
		p->arg.shift_y += b1 - a[1];
		p->arg.zoom *= 1.10;
		p->arg.iterations += 7;
	}
	if (kay == 5)
	{
		a1 = x / (p->arg.zoom / 1.1) + p->arg.shift_x;
		b1 = y / (p->arg.zoom / 1.1) + p->arg.shift_y;
		p->arg.shift_x += a1 - a[0];
		p->arg.shift_y += b1 - a[1];
		p->arg.zoom /= 1.10;
	}
	draw(*p);
	return (0);
}

int	kay1(int key, t_data *p)
{
	if (key == 78)
		p->arg.iterations += 1;
	if (key == 69)
		p->arg.iterations -= 1;
	if (key == 125)
		p->arg.shift_y -= 10 / p->arg.zoom;
	if (key == 126)
		p->arg.shift_y += 10 / p->arg.zoom;
	if (key == 124)
		p->arg.shift_x -= 10 / p->arg.zoom;
	if (key == 123)
		p->arg.shift_x += 10 / p->arg.zoom;
	if (key == 31 && p->arg.color < 1)
		p->arg.color += 0.01;
	if (key == 35 && p->arg.color > 0.0)
		p->arg.color -= 0.01;
	draw(*p);
	return (key);
}

int	kay2(int key, t_data *p)
{
	if (key == 53)
		exit(0);
	if (key == 37)
	{
		(p->arg.is_locked == 1) ? (p->arg.is_locked = 0) :
		(p->arg.is_locked = 1);
	}
	if (key == 40)
	{
		(p->arg.lok == 0) ? (p->arg.lok = 1) :
		(p->arg.lok = 0);
	}
	return (key);
}

int	cikle(t_data *p)
{
	if (p->arg.lok)
		return (0);
	if (!p->arg.ckl && p->arg.color <= 1.0)
		p->arg.color += 0.01;
	else if (p->arg.color > 1.0 && !p->arg.ckl)
		p->arg.ckl = 1;
	else if (p->arg.ckl && p->arg.color >= 0.0)
		p->arg.color -= 0.01;
	else if (p->arg.color <= 0.00)
		p->arg.ckl = 0;
	draw(*p);
	return (0);
}
