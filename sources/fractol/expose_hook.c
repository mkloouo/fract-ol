/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:22:17 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 18:13:03 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <ftio.h>
#include <ftrange.h>
#include <ftcomplex.h>

int						expose_hook(t_fwin *fw)
{
	int					width;
	int					height;
	int					iter;

	width = fw->window->image->width;
	height = fw->window->image->height;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			iter = fw->fractals[fw->type](fw, i, j);
			put_pixel(fw->window->image, get_vec3i(i, j,
			(RGB_COLOR(00, (k % 255), (k % 255), (k % 255)))));
		}
	}
	update_window(fw->window);
	return (1);
}
