/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 05:02:24 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/31 19:28:59 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static long double		interpolate(long double start, long double end,
									long double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void					zoom_fractal(int in, t_fractal *f)
{
	long double			mouse_x;
	long double			mouse_y;
	long double			interpolation;

	interpolation = (in ? 1 / (1.05) : (1.05));
	mouse_x = (long double)(f->sxt - f->sxf) * (f->window->mouse->current->x -
		f->mx) / (FRACTAL_WIDTH - f->mx) + f->sxf;
	mouse_y = (long double)(f->syt - f->syf) * (f->window->mouse->current->y -
		f->my) / (FRACTAL_HEIGHT - f->my) + f->syf;
	f->sxf = interpolate(mouse_x, f->sxf, interpolation);
	f->syf = interpolate(mouse_y, f->syf, interpolation);
	f->sxt = interpolate(mouse_x, f->sxt, interpolation);
	f->syt = interpolate(mouse_y, f->syt, interpolation);
}
