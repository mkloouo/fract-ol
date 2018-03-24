/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:05:27 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 21:52:04 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftcomplex.h>
#include <math.h>

t_complex				pow_complex(t_complex *c, int power)
{
	t_complex			p;
	float				mod;
	float				arg;

	if (power > 0)
	{
		mod = pow(mod_complex(c), power);
		arg = (float)power * arg_complex(c);
		p.r = mod * cos(arg);
		p.i = mod * sin(arg);
	}
	else
		return get_complex(0, 0);
	return (p);
}
