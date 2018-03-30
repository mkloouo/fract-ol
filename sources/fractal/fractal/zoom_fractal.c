/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 05:02:24 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 22:16:43 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static long double		interpolate(long double start, long double end,
									long double interpolation)
{
	return start + ((end - start) * interpolation);
}

void					zoom_fractal(int in, t_fractal *f)
{
	long double			mouse_x;
	long double			mouse_y;
	long double			interpolation;

	interpolation = 1.0 / (in ? (1.05) : (1.0 / 1.05));
	mouse_x = (long double)(f->window->mouse->current->x) / (f->window->width /
			 (f->sxt - f->sxf))	+ f->sxf;
	mouse_y = (long double)(f->window->mouse->current->y) / (f->window->height /
			 (f->syt - f->syf)) + f->syf;
	f->sxf = interpolate(mouse_x, f->sxf, interpolation);
	f->syf = interpolate(mouse_y, f->syf, interpolation);
	f->sxt = interpolate(mouse_x, f->sxt, interpolation);
	f->syt = interpolate(mouse_y, f->syt, interpolation);
}
