/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:00:30 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 17:52:22 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <ftstring.h>

int						get_fractal(char *name)
{
	if (ft_strcmp(name, MANDELBROT_NAME) == 0)
		return (MANDELBROT_TYPE);
	else
		return (-1);
}
