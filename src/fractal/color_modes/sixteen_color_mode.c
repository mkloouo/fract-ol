/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixteen_color_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:33:16 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/31 19:43:16 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int						sixteen_color_mode(t_fractal *f, int iter)
{
	float				normalized;
	int					mapped;

	iter = f->noise ? rand() * iter : iter;
	normalized = sqrt(iter / (float)f->max_iter);
	mapped = (int)(255 * normalized / 1) % 16;
	return (RGB_COLOR(0, (mapped / 1) % 2 * 255,
			(mapped / 2) % 2 * 255,
			(mapped / 4) % 2 * 255));
}
