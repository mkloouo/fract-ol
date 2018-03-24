/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fractal_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:32:42 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 19:32:07 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <image.h>
#include <window.h>
#include <fractal.h>

void					update_fractal_window(t_fractal *f)
{
	int					i;
	int					j;
	t_vec3i				pixel;

	pixel = get_vec3i(0, 0, 0);
	i = 0;
	while (!(j = 0) && i < f->window->height)
	{
		while (j < f->window->width)
		{
			set_vec3i(&pixel, i, j, f->fractals[f->type](f, i, j));
			pixel.z = RGB_COLOR(00, 00, 00, pixel.z * 20% 255);
			put_pixel(f->window->image, &pixel);
			j++;
		}
		i++;
	}
	update_window(f->window);
}
