/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:00:30 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/31 18:41:35 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <ftstring.h>

int						get_fractal(char *name)
{
	if (ft_strcmp(name, MANDELBROT_NAME) == 0)
		return (MANDELBROT_TYPE);
	else if (ft_strcmp(name, JULIA_NAME) == 0)
		return (JULIA_TYPE);
	else if (ft_strcmp(name, NEWTON_NAME) == 0)
		return (NEWTON_TYPE);
	else if (ft_strcmp(name, BURNING_SHIP_NAME) == 0)
		return (BURNING_SHIP_TYPE);
	else if (ft_strcmp(name, TRICORN_NAME) == 0)
		return (TRICORN_TYPE);
	else if (ft_strcmp(name, SPIDER_NAME) == 0)
		return (SPIDER_TYPE);
	else if (ft_strcmp(name, CIRCLE_NAME) == 0)
		return (CIRCLE_TYPE);
	else if (ft_strcmp(name, BIOMORPH_NAME) == 0)
		return (BIOMORPH_TYPE);
	else if (ft_strcmp(name, MANDELBROT_CUSTOM_NAME) == 0)
		return (MANDELBROT_CUSTOM_TYPE);
	else
		return (-1);
}
