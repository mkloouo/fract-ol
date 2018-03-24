/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:55:19 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 17:28:08 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <stdlib.h>

int						key_press_hook(int btn, t_fractal *f)
{
	if (QUIT_BUTTON(btn))
	{
		delete_fractal(&f);
		exit(0);
	}
	else if (ZOOM_BUTTON(btn))
	{
		f->zoom += (ZOOM_IN(btn) ? (0.01) : (-0.01));
	/* else if (MOVE_BUTTON(btn)) */
	/* { */
	/* 	if (MOVE_HOR(btn)) */
	/* 		f->mx += (MOVE_RIGHT(btn) ? (-0.5) : (0.5)); */
	/* 	else */
	/* 		f->my += (MOVE_UP(btn) ? (0.5) : (-0.5)); */
	/* } */
	}
	else
		return (-1);
	update_window(f->window);
	return (0);
}
