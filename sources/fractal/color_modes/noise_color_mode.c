/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise_color_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:04:56 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 04:58:56 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int						noise_color_mode(t_fractal *f, int i)
{
	static int			generated = 0;
	float				normalized;
	int					mapped;

	if (!generated)
	{
		srand(time(NULL));
		generated = 1;
	}
	normalized = sqrt(i / (float)f->iter);
	mapped = rand() * (int)(255 * normalized / 1) % 255;
	if (i == f->iter)
		return (RGB_COLOR(0, 0, 0, mapped));
	else if (i < f->iter / 3)
		return (RGB_COLOR(0, 0, mapped, 0));
	else if (i < f->iter / 2)
		return (RGB_COLOR(0, mapped, mapped, 0));
	else
		return (RGB_COLOR(0, 0, 0, mapped));
}
