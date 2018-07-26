/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:23:06 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/31 15:10:51 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int						mouse_press_hook(int btn, int x, int y, t_fractal *f)
{
	if (IN_IMAGE(x, y, FRACTAL_WIDTH, FRACTAL_HEIGHT))
	{
		if (MOUSE_SCROLL(btn))
		{
			zoom_fractal(SCROLL_UP_BUTTON(btn), f);
			update_fractal(f);
		}
		set_vec2i(f->window->mouse->press, x, y);
		f->window->mouse->btn = btn;
		f->window->mouse->pressed = 1;
	}
	return (0);
}
