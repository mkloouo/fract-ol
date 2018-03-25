/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:55:19 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/25 21:30:23 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <stdlib.h>
#include <stdio.h>

int						key_press_hook(int btn, t_fractal *f)
{
	if (QUIT_BUTTON(btn))
	{
		delete_fractal(&f);
		exit(0);
	}
	else if (MOVE_BUTTON(btn))
	{
		if (MOVE_HOR(btn))
			f->mx += MOVE_RIGHT(btn) ? 5 : -5;
		else if (MOVE_VER(btn))
			f->my += MOVE_DOWN(btn) ? 5 : -5;
	}
	else if (btn == NUM_ONE_KC)
		f->type = MANDELBROT_TYPE;
	else if (btn == NUM_TWO_KC)
		f->type = JULIA_TYPE;
	else
		return (-1);
	update_fractal_window(f);
	return (0);
}
