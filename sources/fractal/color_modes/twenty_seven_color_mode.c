/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twenty_seven_color_mode.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 03:41:55 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 03:56:19 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <math.h>

int						twenty_seven_color_mode(t_fractal *f, int i)
{
	float				normalized;
	int					mapped;

	normalized = sqrt(i / (float)f->iter);
	mapped = (int)(255 * normalized / 1) % 27;
	return (RGB_COLOR(0, (mapped / 1) % 3 * 255,
			(mapped / 2) % 3 * 255,
			(mapped / 4) % 3 * 255));
}
