/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_color_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:16:50 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 21:14:41 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int						blue_color_mode(t_fractal *f, int i)
{
	float				normalized;
	int					mapped;

	normalized = i / (float)f->iter;
	mapped = (int)(255 * normalized / 1);
	return (RGB_COLOR(0, 0, 0, mapped % 255));
}
