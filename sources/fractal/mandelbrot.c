/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:45:30 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 21:43:56 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftrange.h>
#include <ftcomplex.h>
#include <fractal.h>

int						mandelbrot(t_fractal *f, int i, int j)
{
	int					n;
	t_complex			c;
	t_complex			z;

	n = 0;
	c = get_complex(ft_mapf(i, get_rangef(0, f->window->height), get_rangef(-2, 2)),
					ft_mapf(j, get_rangef(0, f->window->width), get_rangef(-2, 2)));
	z = get_complex(0, 0);
	while (n < f->iter)
	{
		t_complex temp = pow_complex(&z, 2);
		z = add_complex(&temp, &c);
		if (mod_complex(&z) > f->bail)
			break ;
		n++;
	}
	return (n);
}
