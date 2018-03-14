/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:27:40 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 14:43:16 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <ftstring.h>

int						get_fractal_type(char *name)
{
	if (ft_strcmp(name, MANDELBROT_NAME) == 0)
		return (MANDELBROT_TYPE);
	else
		return (-1);
}
