/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:29:25 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 17:43:55 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int						mouse_move_hook(int x, int y, t_fractal *f)
{
	if (IN_IMAGE(x, y, f->window->image->width, f->window->image->height))
		set_vec2i(f->window->mouse->cv, x, y);
	return (1);
}
