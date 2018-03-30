/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:45:30 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 12:53:45 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static void				complex_pow_2(long double *a, long double *b)
{
	long double			ta;
	long double			tb;

	ta = *a * *a - *b * *b;
	tb = 2 * *a * *b;
	*a = ta;
	*b = tb;
}

int						mandelbrot(t_fractal *f, long double i, long double j)
{
	int					n;
	long double			a;
	long double			b;

	n = 0;
	a = i;
	b = j;
	while (n < f->max_iter)
	{
		if (a * a + b * b > f->bail)
			break ;
		complex_pow_2(&a, &b);
		a += i;
		b += j;
		n++;
	}
	return (n);
}
