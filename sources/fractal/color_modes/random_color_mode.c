/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_color_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:49:16 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 21:06:28 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <time.h>
#include <stdlib.h>

int						random_color_mode(t_fractal *f, int i)
{
	static int			generated = 0;
	int					color;
	float				normalized;
	int					mapped;

	if (!generated)
	{
		srand(time(NULL));
		generated = 1;
	}
	normalized = i / (float)f->iter;
	mapped = (int)(255 * normalized / 1);
	if (i == f->iter || i == f->bail / 2)
	{
		color = rand() * mapped % 255;
		return (RGB_COLOR(0, rand() * mapped % 255,
		rand() * mapped % 255,
		rand() * mapped % 255));
	}
	return (0);
}
