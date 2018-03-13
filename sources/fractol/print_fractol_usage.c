/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractol_usage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:24:47 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 20:26:04 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <ftio.h>

void					print_fractol_usage(char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putendl(" fractal\n\tMandelbrot");
}
