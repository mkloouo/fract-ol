/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:23:41 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/31 17:56:26 by modnosum         ###   ########.fr       */
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

int						julia(t_fractal *f, long double i, long double j)
{
	int					n;
	long double			a;
	long double			b;

	n = 0;
	a = (long double)(f->window->mouse->current->x) /
		((f->window->width) / (f->sxt - f->sxf)) + f->sxf;
	b = (long double)(f->window->mouse->current->y) /
		((f->window->height) / (f->syt - f->syf)) + f->syf;
	while (n < f->max_iter)
	{
		if (j * j + i * i > f->bail)
			break ;
		complex_pow_2(&j, &i);
		j += a;
		i += b;
		n++;
	}
	return (n);
}
