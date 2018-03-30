/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal_by_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:54:38 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 07:57:25 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

char					*get_fractal_by_number(int n)
{
	if (n == MANDELBROT_TYPE)
		return (MANDELBROT_NAME);
	else if (n == JULIA_TYPE)
		return (JULIA_NAME);
	else if (n == NEWTON_TYPE)
		return (NEWTON_NAME);
	else if (n == BURNING_SHIP_TYPE)
		return (BURNING_SHIP_NAME);
	else
		return ("Unknown Fractal");
}
