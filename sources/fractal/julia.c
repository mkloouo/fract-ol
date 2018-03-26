/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:23:41 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 19:19:52 by modnosum         ###   ########.fr       */
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

int						julia(t_fractal *f, int i, int j)
{
	int					n;
	float				a;
	float				b;
	float				ia;
	float				ib;

	n = 0;
	ia = ft_mapf(f->window->mouse->cv->x, get_rangef(0, f->window->width),
				get_rangef(-1, 1));
	ib = ft_mapf(f->window->mouse->cv->y, get_rangef(0, f->window->height),
				get_rangef(-1, 1));
	a = ft_mapf(i, get_rangef(0, f->window->height),
				get_rangef(-1 * f->zoom, f->zoom));
	b = ft_mapf(j, get_rangef(0, f->window->width),
				get_rangef(-1 * f->zoom, f->zoom));
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
