/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:23:41 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 21:12:51 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int						julia(t_fractal *f, int i, int j)
{
	int					n;
	float				a;
	float				b;
	float				ia;
	float				ib;

	n = 0;
	ia = ((2) * (float)(f->window->mouse->current->x)) /
		(f->window->width) - 1;
	ib = ((2) * (float)(f->window->mouse->current->y)) /
		(f->window->height) - 1;
	a = ((2 * (float)f->zoom) * i) / (f->window->height) - f->zoom;
	b = ((2 * (float)f->zoom) * j) / (f->window->width) - f->zoom;
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
