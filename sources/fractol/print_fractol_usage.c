/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractol_usage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:45:23 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 14:50:15 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <ftio.h>

void					print_fractol_usage(char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putendl(" fractal-type\nWhere fractal-type:\n\tMandelbrot");
}
