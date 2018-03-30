/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 04:44:41 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 13:03:58 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <math.h>

static void				complex_pow_3(long double *a,
						long double *b,
						long double *c,
						long double *d)
{
	double				t1;
	double				t2;
	double				p;

	t1 = *a;
	t2 = *b;
	p = (t1 * t1 + t2 * t2);
	p = p * p;
	*a = (float)2 / 3 * t1 + (t1 * t1 - t2 * t2) / (float)(3 * p);
	*b = (float)2 / 3 * t2 * (1 - t1 / p);
	*c = fabs(t1 - (double)*a);
	*d = fabs(t2 - (double)*b);
}

int						newton(t_fractal *f, long double i, long double j)
{
	int					n;
	long double			c;
	long double			d;

	n = 0;
	c = i;
	d = j;
	while (n < f->max_iter)
	{
		if (i * i + j * j >= f->max || c * c + d * d <= f->min)
			break ;
		complex_pow_3(&j, &i, &c, &d);
		n++;
	}
	return (n);
}
