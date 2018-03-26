/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_color_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:00:05 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 19:19:34 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftrange.h>
#include <fractal.h>

int						blend_color_mode(int iterations, int max_iter)
{
	float				normalized;
	int					mapped;

	normalized = ft_mapf(iterations, get_rangef(0, max_iter),
						get_rangef(0, 1));
	mapped = (int)ft_mapf(normalized, get_rangef(0, 1),
						get_rangef(0, 255));
	return (RGB_COLOR(00, mapped % 255, mapped % 255,
			mapped % 255));
}
