/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:43:29 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 20:11:22 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <mlx.h>
#include <ftstdlib.h>

void					delete_window(t_window **wp)
{
	if (wp && *wp)
	{
		delete_mouse(&(*wp)->mouse);
		delete_keyboard(&(*wp)->keyboard);
		delete_image(&(*wp)->image);
		if ((*wp)->server && (*wp)->window)
			mlx_destroy_window((*wp)->server, (*wp)->window);
		ft_memdel((void**)wp);
	}
}
