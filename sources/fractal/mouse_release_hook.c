/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:28:12 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/25 19:33:56 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int						mouse_release_hook(int btn, int x, int y, t_fractal *f)
{
	if (IN_IMAGE(x, y, f->window->image->width, f->window->image->height))
	{
		(void)x;
		(void)y;
		f->window->mouse->btn = btn;
		f->window->mouse->pressed = 0;
	}
	return (0);
}
