/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:55:19 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 18:08:17 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdlib.h>

int						key_press_hook(int btn, t_fwin *fw)
{
	if (QUIT_BUTTON(btn))
		exit(1);
	else if (ZOOM_BUTTON(btn))
		fw->zoom += (ZOOM_IN(btn) ? (0.01) : (-0.01));
	else if (MOVE_BUTTON(btn))
	{
		if (MOVE_HOR(btn))
			fw->mx += (MOVE_RIGHT(btn) ? (-0.5) : (0.5));
		else
			fw->my += (MOVE_UP(btn) ? (0.5) : (-0.5));
	}
	else
		return (-1);
	return (expose_hook(fw));
}
