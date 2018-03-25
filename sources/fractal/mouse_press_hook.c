/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:23:06 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/25 19:32:34 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int						mouse_press_hook(int btn, int x, int y, t_fractal *f)
{
	if (IN_IMAGE(x, y, f->window->image->width, f->window->image->height))
	{
		set_vec2i(f->window->mouse->pv, x, y);
		f->window->mouse->btn = btn;
		f->window->mouse->pressed = 1;
	}
	return (0);
}
