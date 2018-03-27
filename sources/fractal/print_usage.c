/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:14:55 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 04:43:35 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <ftio.h>

void					print_usage(char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putendl((" fractal-type\nWhere fractal-type:\n"
				"\t" MANDELBROT_NAME "\n"
				"\t" JULIA_NAME "\n"
				"\t" NEWTON_NAME "\n"
				"\t" BURNING_SHIP_NAME));
}
