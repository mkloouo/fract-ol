/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:28:12 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/28 20:04:49 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int						mouse_release_hook(int btn, int x, int y, t_fractal *f)
{
	if (IN_IMAGE(x, y, f->w->image->width, f->w->image->height))
	{
		set_vec2i(f->w->mouse->release, x, y);
		f->w->mouse->btn = btn;
		f->w->mouse->pressed = 0;
	}
	return (0);
}
