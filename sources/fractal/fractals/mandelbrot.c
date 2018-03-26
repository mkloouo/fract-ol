/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:45:30 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 21:07:26 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftrange.h>
#include <fractal.h>
#include <stdio.h>

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

	n = 0;
	ia = ((2 * (float)f->zoom * (i - f->mx)) / (f->window->height)) - f->zoom;
	ib = ((2 * (float)f->zoom * (j - f->my)) / (f->window->width)) - f->zoom;
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
