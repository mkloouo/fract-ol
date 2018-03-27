/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 04:44:41 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 04:44:42 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <math.h>

static void				nuzhno_bolshe_peremennyh(float *a, float *b,
													float *c, float *d)
{
	float t1;
	float t2;
	float p;

	t1 = *a;
	t2 = *b;
	p = (t1 * t1 + t2 * t2);
	p = p * p;
	*a = (float)2 / 3 * t1 + (t1 * t1 - t2 * t2) / (float)(3 * p);
	*b = (float)2 / 3 * t2 * (1 - t1 / p);
	*c = fabs(t1 - *a);
	*d = fabs(t2 - *b);
}

int						newton(t_fractal *f, int i, int j)
{
	int					n;
	float				a;
	float				b;
	float				c;
	float				d;

	n = 0;
	a = ((2 * (float)f->zoom) * (j - f->mx)) / (f->window->width) - f->zoom;
	b = ((2 * (float)f->zoom) * (i - f->my)) / (f->window->height) - f->zoom;
	c = a;
	d = b;
	while (n < f->iter)
	{
		if (a * a + b * b >= f->max || c * c + d * d <= f->min)
			break ;
		nuzhno_bolshe_peremennyh(&a, &b, &c, &d);
		n++;
	}
	return (n);
}
