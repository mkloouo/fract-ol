/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:29:25 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/31 19:29:22 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <stdio.h>

int						mouse_move_hook(int x, int y, t_fractal *f)
{
	if (IN_IMAGE(x, y, FRACTAL_WIDTH, FRACTAL_HEIGHT))
	{
		set_vec2i(f->window->mouse->previous, f->window->mouse->current->x,
				f->window->mouse->current->y);
		set_vec2i(f->window->mouse->current, x, y);
		if (f->window->mouse->current->x != f->window->mouse->previous->x &&
			f->window->mouse->current->x != f->window->mouse->previous->x)
		{
			if (LEFT_BUTTON(f->window->mouse->btn) && f->window->mouse->pressed)
			{
				f->mx += f->window->mouse->current->x -
						f->window->mouse->press->x;
				f->my += f->window->mouse->current->y -
						f->window->mouse->press->y;
				set_vec2i(f->window->mouse->press, f->window->mouse->current->x,
						f->window->mouse->current->y);
			}
			update_fractal(f);
		}
	}
	else
		f->window->mouse->pressed = 0;
	return (1);
}
