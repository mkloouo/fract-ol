/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:15:20 by modnosum          #+#    #+#             */
/*   Updated: 2018/02/23 23:32:06 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <image.h>

unsigned int			map_color(unsigned int c1, unsigned int c2, float ratio)
{
	unsigned int		a;
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;

	a = (int)(((c2 & 0xFF000000) >> 24) * ratio
			+ ((c1 & 0xFF000000) >> 24) * (1 - ratio));
	r = (int)(((c2 & 0x00FF0000) >> 16) * ratio
			+ ((c1 & 0x00FF0000) >> 16) * (1 - ratio));
	g = (int)(((c2 & 0x0000FF00) >> 8) * ratio
			+ ((c1 & 0x0000FF00) >> 8) * (1 - ratio));
	b = (int)((c2 & 0x000000FF) * ratio
			+ (c1 & 0x000000FF) * (1 - ratio));
	return (RGB_COLOR(a, r, g, b));
}
