/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:45:30 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 08:19:09 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static void				complex_pow_2(float *a, float *b)
{
	float				ta;
	float				tb;

	ta = *a * *a - *b * *b;
	tb = 2 * *a * *b;
	*a = ta;
	*b = tb;
}

int						mandelbrot(t_fractal *f, int i, int j)
{
	int					n;
	float				a;
	float				b;
	float				ia;
	float				ib;

	/*
	newV = ((newMax - newMin) * (oldV - oldMin) / (oldMax - oldMin)) + newMin
	*/

// TODO: Finish mandelbrot
	n = 0;
	ia = ((f->scale_x->y - f->scale_x->x) * (j - f->mx) / (f->window->width +
		f->mx)) + f->scale_x->x;
	ib = ((f->scale_y->y - f->scale_y->x) * (i - f->my) / (f->window->height +
		f->my)) + f->scale_y->x;
	a = ia;
	b = ib;
	while (n < f->iter)
	{
		if (a * a + b * b > f->bail)
			break ;
		complex_pow_2(&a, &b);
		a += ia;
		b += ib;
		n++;
	}
	return (n);
}
