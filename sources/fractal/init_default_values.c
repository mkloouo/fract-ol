/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 06:42:45 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/28 20:05:22 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void					init_default_values(t_fractal *f)
{
	f->max_iter = DEFAULT_MAX_ITER;
	f->bail = DEFAULT_BAIL;
	f->min = DEFAULT_MIN;
	f->max = DEFAULT_MAX;
}
