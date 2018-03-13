/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:26:32 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 20:29:18 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <ftio.h>
#include <ftstring.h>

void					fractol(char *fractal)
{
	if (ft_strcmp("Mandelbrot", fractal) == 0)
		ft_putstr("you chose: ");
	else
		ft_putstr("invalid fractal: ");
	ft_putendl(fractal);
}
