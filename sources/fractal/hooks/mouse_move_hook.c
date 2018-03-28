/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:29:25 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/28 20:04:56 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <stdio.h>

int						mouse_move_hook(int x, int y, t_fractal *f)
{
	if (IN_IMAGE(x, y, f->w->image->width, f->w->image->height))
	{
		set_vec2i(f->w->mouse->current, x, y);
		if (f->w->mouse->current->x != f->w->mouse->previous->x &&
			f->w->mouse->current->x != f->w->mouse->previous->x)
			if (f->type == JULIA_TYPE)
				update_fractal(f);
	}
	else
		f->w->mouse->pressed = 0;
	return (1);
}
