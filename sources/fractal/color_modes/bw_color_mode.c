/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bw_color_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:17:18 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 21:28:39 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <math.h>

int						bw_color_mode(t_fractal *f, int iter)
{
	float				normalized;
	int					mapped;

	normalized = sqrt(iter / (float)f->max_iter);
	mapped = (int)(255 * normalized / 1);
	return (RGB_COLOR(00, mapped % 255, mapped % 255,
			mapped % 255));
}
