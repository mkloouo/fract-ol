/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 05:02:24 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 08:10:34 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static float			interpolate(float start, float end, float interpolation)
{
	return start + ((end - start) * interpolation);
}

void					zoom_fractal(int in, t_fractal *f)
{
	float				mouse_x;
	float				mouse_y;
	float				interpolation;
	/*
	newV = ((newMax - newMin) * (oldV - oldMin) / (oldMax - oldMin)) + newMin
	*/
	interpolation = 1.0 / (in ? (1.05) : (1.0 / 1.05));
	mouse_x = (float)(f->scale_x->y - f->scale_x->x) *
		(f->window->mouse->current->x) / (float)f->window->width +
		f->scale_x->x;
	mouse_y = (float)(f->scale_y->y - f->scale_y->x) *
		(f->window->mouse->current->y) / (float)f->window->height +
		f->scale_y->x;
	set_vec2f(f->scale_x, interpolate(mouse_x, f->scale_x->x, interpolation),
		interpolate(mouse_x, f->scale_x->y, interpolation));
	set_vec2f(f->scale_y, interpolate(mouse_y, f->scale_y->x, interpolation),
		interpolate(mouse_y, f->scale_y->y, interpolation));
}
