/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_custom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:39:45 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/31 19:18:00 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static void				complex_pow_2(long double *a, long double *b,
										long double c, long double d)
{
	long double			ta;
	long double			tb;

	ta = *a * *a - *b * *b;
	tb = 2 * *a * *b;
	*a = ta * c - ta;
	*b = tb * d - tb;
}

int						mandelbrot_custom(t_fractal *f, long double i,
						long double j)
{
	int					n;
	long double			a;
	long double			b;
	long double			c;
	long double			d;

	n = 0;
	a = j;
	b = i;
	c = (long double)(f->window->mouse->current->x) /
		((f->window->width) / (f->sxt - f->sxf)) + f->sxf;
	d = (long double)(f->window->mouse->current->y) /
		((f->window->height) / (f->syt - f->syf)) + f->syf;
	while (n < f->max_iter)
	{
		if (a * a + b * b > f->bail)
			break ;
		complex_pow_2(&a, &b, c, d);
		a += j;
		b += i;
		n++;
	}
	return (n);
}
