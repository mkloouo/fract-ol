/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:45:30 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 18:10:12 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftcomplex.h>
#include <fractal.h>

int						mandelbrot(t_fractal *f, int i, int j)
{
	int					n;
	t_complex			c;
	t_complex			z;
	t_complex			zpow2;

	n = 0;
	c = get_complex(i, j);
	// TODO: map i j values to -2, 2
	z = get_complex(0, 0);
	while (n < f->iter)
	{
		zpow2 = pow_complex(&z, 2);
		z = add_complex(&zpow2, &c);
		if (mod_complex(&z) > f->bail)
			break ;
		n++;
	}
	return (n);
}
