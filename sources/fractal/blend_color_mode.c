/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_color_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:00:05 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/25 21:00:06 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int						blend_color_mode(int iterations)
{
	return (RGB_COLOR(00, iterations % 255, iterations % 255,
			iterations % 255));
}
