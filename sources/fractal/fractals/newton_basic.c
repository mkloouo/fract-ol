/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 22:27:47 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 04:12:11 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static void				complex_pow_2(float a, float b, float *c, float *d)
{
	float				ta;
	float				tb;

	ta = a * a - b * b;
	tb = 2 * a * b;
	*c = ta;
	*d = tb;
}

static void				complex_pow_3(float a, float b, float *c, float *d)
{
	float				ta;
	float				tb;

	ta = a * a * a - 3 * a * b * b;
	tb = 3 * a * a * b - b * b * b;
	*c = ta;
	*d = tb;
}

int						newton_basic(t_fractal *f, int i, int j)
{
	int					n;
	float				a;
	float				b;

	n = 0;
	a = ((2 * (float)f->zoom) * i) / (f->window->height) - f->zoom;
	b = ((2 * (float)f->zoom) * j) / (f->window->width) - f->zoom;
	while (n < f->iter)
	{
		if (a * a + b * b > f->bail)
			break ;
		a = a - (1 * (a - 1) / a);
		b = b - (1 * (b - 1) / b);
		n++;
	}
	return (n);
}
