/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:14:35 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 03:59:28 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <mlx.h>

void					add_hook(t_window *w, int type, int (*func)(),
void *func_argument)
{
	int					mask;

	if (type == KEY_RELEASE || type == KEY_PRESS)
		mask = (type == KEY_RELEASE) ? KEY_RELEASE_MASK : KEY_PRESS_MASK;
	else if (type == MOUSE_BUTTON_PRESS || type == MOUSE_BUTTON_RELEASE)
		mask = (type == MOUSE_BUTTON_RELEASE) ? MOUSE_BUTTON_RELEASE_MASK
			: MOUSE_BUTTON_PRESS_MASK;
	else if (type == MOTION_NOTIFY || type == EXPOSE)
		mask = (type == EXPOSE) ? (EXPOSE_MASK) : (MOTION_NOTIFY_MASK);
	else
		return ;
	mlx_hook(w->window, type, mask, func, func_argument);
}
