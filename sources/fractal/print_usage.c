/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:14:55 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 23:28:45 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <ftio.h>

void					print_usage(char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putendl((" fractal-type\nWhere fractal-type:\n"
				"\tMandelbrot\n"
				"\tJulia\n"
				"\tNewton Basic\n"
				"\tBurning Ship"));
}
