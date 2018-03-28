/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_color_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:15:25 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/28 19:50:20 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <math.h>

int						red_color_mode(t_fractal *f, int i)
{
	float				normalized;
	int					mapped;

	normalized = sqrt(i / (float)f->max_iter);
	mapped = (int)(255 * normalized / 1);
	return (RGB_COLOR(0, mapped % 255, 0, 0));
}
