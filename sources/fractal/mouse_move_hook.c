/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:29:25 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/25 21:15:41 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int						mouse_move_hook(int x, int y, t_fractal *f)
{
	if (IN_IMAGE(x, y, f->window->image->width, f->window->image->height))
	{
		f->window->mouse->cv->x = x;
		f->window->mouse->cv->y = y;
		if (f->window->mouse->pressed && LEFT_BUTTON(f->window->mouse->btn))
		{
			f->mx += f->window->mouse->cv->x - f->window->mouse->pv->x;
			f->my += f->window->mouse->cv->y - f->window->mouse->pv->y;
			set_vec2i(f->window->mouse->pv, f->window->mouse->cv->x,
						f->window->mouse->cv->y);
			update_fractal_window(f);
		}
	}
	return (1);
}
