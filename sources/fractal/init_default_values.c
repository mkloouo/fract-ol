/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 06:42:45 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 07:11:48 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void					init_default_values(t_fractal *f)
{
	f->scale_x = alloc_vec2f(-1 * DEFAULT_ZOOM, DEFAULT_ZOOM);
	f->scale_y = alloc_vec2f(-1 * DEFAULT_ZOOM, DEFAULT_ZOOM);	
	f->iter = DEFAULT_ITERATIONS;
	f->bail = DEFAULT_BAIL;
	f->min = DEFAULT_MIN;
	f->max = DEFAULT_MAX;
	f->mx = DEFAULT_MX;
	f->my = DEFAULT_MY;
}
