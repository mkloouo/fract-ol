/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise_color_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:04:56 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 04:11:18 by modnosum         ###   ########.fr       */
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
	mapped = rand() * (int)(255 * normalized / 1);
	if (i > 0 && i < (f->iter / 2))
		return (RGB_COLOR(0, (mapped * i) % 127, 0, (mapped * i) % 127));
	else if (i > 0)
		return (RGB_COLOR(0, 0, 0, (mapped % i * 12) % 255));
	else
		return (RGB_COLOR(0, 0, 0, 0));
}
