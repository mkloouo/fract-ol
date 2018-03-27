/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:55:19 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 06:43:23 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <stdlib.h>

static void				handle_movement(int btn, t_fractal *f)
{
	if (MOVE_HOR(btn))
		f->mx += MOVE_RIGHT(btn) ? 5 : -5;
	else if (MOVE_VER(btn))
		f->my += MOVE_DOWN(btn) ? 5 : -5;
}

int						key_press_hook(int btn, t_fractal *f)
{
	if (QUIT_BUTTON(btn))
	{
		delete_fractal(&f);
		exit(0);
	}
	else if (MOVE_BUTTON(btn))
		handle_movement(btn, f);
	else if (RESET_BUTTON(btn))
		init_default_values(f);
	else if (btn == C_KC)
	{
		f->color_mode++;
		f->color_mode %= COLOR_MODES;
	}
	else
		return (-1);
	update_fractal(f);
	return (0);
}
