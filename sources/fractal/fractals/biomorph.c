/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biomorph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:54:30 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/31 18:42:42 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static void			complex_oper(long double *a, long double *b)
{
	long double		t1;
	long double		t2;

	t1 = *a;
	t2 = *b;
	*a = t1 * t1 * t1 * t1 + t2 * t2 * t2 * t2 - 6 * t1 * t1 * t2 * t2;
	*b = 4 * t1 * t1 * t1 * t2 - 4 * t1 * t2 * t2 * t2;
}

int					biomorph(t_fractal *f, long double i, long double j)
{
	int				n;
	long double		a;
	long double		b;

	a = (long double)(f->window->mouse->current->x) /
		((f->window->width) / (f->sxt - f->sxf)) + f->sxf;
	b = (long double)(f->window->mouse->current->y) /
		((f->window->height) / (f->syt - f->syf)) + f->syf;
	n = 0;
	while (n < f->max_iter)
	{
		if (i * i > 70 || j * j > 70)
			break ;
		complex_oper(&i, &j);
		i += a;
		j += b;
		n++;
	}
	return (n);
}
