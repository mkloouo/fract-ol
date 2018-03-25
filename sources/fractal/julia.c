/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:23:41 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/25 21:28:47 by modnosum         ###   ########.fr       */
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
	ia = ft_mapf(f->window->mouse->cv->y, get_rangef(0, f->window->height),
				 get_rangef(-1, 1));
	ib = ft_mapf(f->window->mouse->cv->x, get_rangef(0, f->window->width),
				 get_rangef(-1, 1));
	a = ia;
	b = ib;
	(void)i;
	(void)j;
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
