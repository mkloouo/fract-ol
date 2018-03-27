/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 23:22:29 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 06:25:15 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftrange.h>
#include <fractal.h>
#include <math.h>

static void				complex_pow_2(float *a, float *b)
{
	float				ta;
	float				tb;

	ta = *a * *a - *b * *b;
	tb = 2 * fabs(*a * *b);
	*a = ta;
	*b = tb;
}

int						burning_ship(t_fractal *f, int i, int j)
{
	int					n;
	float				a;
	float				b;
	float				ia;
	float				ib;

	n = 0;
	ia = i;
	ib = j;
//	ia = ((2 * (float)f->zoom * j) / (f->window->width)) - f->zoom;
//	ib = ((2 * (float)f->zoom * i) / (f->window->height)) - f->zoom;
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
