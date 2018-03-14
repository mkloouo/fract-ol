/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:29:25 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 17:42:29 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int						mouse_move_hook(int x, int y, t_fwin *fw)
{
	if (IN_IMAGE(x, y, fw->window->image->width, fw->window->image->height))
		set_vec2i(*fw->window->mouse->cv, x, y);
	return (1);
}
