/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 05:02:24 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 13:11:40 by modnosum         ###   ########.fr       */
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
	mouse_x = (f->st - f->sf) * (long double)(f->window->mouse->current->x) /
		(float)f->window->width + f->scale_x->x;
	mouse_y = (f->st - f->sf) * (long double)(f->window->mouse->current->y) /
		(float)f->window->height + f->scale_y->x;
	set_vec2f(f->scale_y, interpolate(mouse_y, f->scale_y->x, interpolation),
			  interpolate(mouse_y, f->scale_y->y, interpolation));
	f->st += 
	
}
